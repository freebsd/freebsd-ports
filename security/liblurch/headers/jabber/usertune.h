/*
 * purple - Jabber Protocol Plugin
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 */

#ifndef PURPLE_JABBER_USERTUNE_H_
#define PURPLE_JABBER_USERTUNE_H_

#include "jabber.h"

/* Implementation of XEP-0118 */

typedef struct _PurpleJabberTuneInfo PurpleJabberTuneInfo;
struct _PurpleJabberTuneInfo {
	char *artist;
	char *title;
	char *album;
	char *track; /* either the index of the track in the album or the URL for a stream */
	int time; /* in seconds, -1 for unknown */
	char *url;
};

void jabber_tune_init(void);

void jabber_tune_set(PurpleConnection *gc, const PurpleJabberTuneInfo *tuneinfo);

#endif /* PURPLE_JABBER_USERTUNE_H_ */
