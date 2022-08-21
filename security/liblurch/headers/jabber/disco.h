/**
 * @file disco.h Jabber Service Discovery
 *
 * purple
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */
#ifndef PURPLE_JABBER_DISCO_H_
#define PURPLE_JABBER_DISCO_H_

#include "jabber.h"

typedef struct _JabberDiscoItem {
	const char *jid;  /* MUST */
	const char *node; /* SHOULD */
	const char *name; /* MAY */
} JabberDiscoItem;

typedef void (JabberDiscoInfoCallback)(JabberStream *js, const char *who,
		JabberCapabilities capabilities, gpointer data);

typedef void (JabberDiscoItemsCallback)(JabberStream *js, const char *jid,
		const char *node, GSList *items, gpointer data);

void jabber_disco_info_parse(JabberStream *js, const char *from,
                             JabberIqType type, const char *id, xmlnode *in_query);
void jabber_disco_items_parse(JabberStream *js, const char *from,
                              JabberIqType type, const char *id, xmlnode *query);

void jabber_disco_items_server(JabberStream *js);

void jabber_disco_info_do(JabberStream *js, const char *who,
		JabberDiscoInfoCallback *callback, gpointer data);

#endif /* PURPLE_JABBER_DISCO_H_ */
