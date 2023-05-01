// SPDX-FileCopyrightText: 2023 Fabrício Moura Jácome
//
// SPDX-License-Identifier: MIT

#include "playlist.h"

Playlist::Playlist(string name) {
  this->name = std::move(name);
  on_queue = 0;
}

Playlist::Playlist(string name, const List<Music*>& music_list) {
  this->name = std::move(name);
  this->music_list = music_list;
  on_queue = 0;
}

void Playlist::setName(string name) { this->name = std::move(name); }

string Playlist::getName() const { return name; }

void Playlist::add_music(Music* music) { music_list.push_back(music); }

void Playlist::remove_music(int index) { music_list.remove(index); }

Music Playlist::next_music() {
  Music* to_play = music_list.get(on_queue)->value;
  cout << "#" << on_queue + 1 << " On Queue:\n";
  if (on_queue < music_list.getSize() - 1) {
    ++on_queue;
    return *to_play;
  } else {
    Music empty;
    return empty;
  }
}

void Playlist::print(int index) const {
  if (music_list.getSize() == 0) {
    cout << "Playlist is empty!\n";
  } else {
    cout << index + 1 << ".\n" << music_list.get(index)->value << '\n';
    if (index < music_list.getSize() - 1) {
      print(++index);
    }
  }
}
