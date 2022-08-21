/**
 * @file presence.h Presence
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
#ifndef PURPLE_JABBER_PRESENCE_H_
#define PURPLE_JABBER_PRESENCE_H_

typedef enum {
	JABBER_PRESENCE_ERROR = -2,
	JABBER_PRESENCE_PROBE = -1,
	JABBER_PRESENCE_AVAILABLE,
	JABBER_PRESENCE_UNAVAILABLE,
	JABBER_PRESENCE_SUBSCRIBE,
	JABBER_PRESENCE_SUBSCRIBED,
	JABBER_PRESENCE_UNSUBSCRIBE,
	JABBER_PRESENCE_UNSUBSCRIBED
} JabberPresenceType;

typedef struct _JabberPresenceChatInfo JabberPresenceChatInfo;
typedef struct _JabberPresence JabberPresence;

#include "buddy.h"
#include "chat.h"
#include "jabber.h"
#include "jutil.h"
#include "xmlnode.h"

struct _JabberPresenceChatInfo {
	GSList *codes;
	xmlnode *item;
};

struct _JabberPresence {
	JabberPresenceType type;
	JabberID *jid_from;
	const char *from;
	const char *to;
	const char *id;

	JabberBuddy *jb;
	JabberChat *chat;
	JabberPresenceChatInfo chat_info;
	xmlnode *caps; /* TODO: Temporary, see presence.c:parse_caps */

	JabberBuddyState state;
	gchar *status;
	int priority;

	char *vcard_avatar_hash;
	char *nickname;

	gboolean delayed;
	time_t sent;
	int idle;
};

typedef void (JabberPresenceHandler)(JabberStream *js, JabberPresence *presence,
                                     xmlnode *child);
void jabber_presence_register_handler(const char *node, const char *xmlns,
                                      JabberPresenceHandler *handler);

void jabber_presence_init(void);
void jabber_presence_uninit(void);

void jabber_set_status(PurpleAccount *account, PurpleStatus *status);

/**
 *	Send a full presence stanza.
 *
 *	@param js       A JabberStream object.
 *	@param force    Force sending the presence stanza, irrespective of whether
 *	                the contents seem to have changed.
 */
void jabber_presence_send(JabberStream *js, gboolean force);

xmlnode *jabber_presence_create(JabberBuddyState state, const char *msg, int priority); /* DEPRECATED */
xmlnode *jabber_presence_create_js(JabberStream *js, JabberBuddyState state, const char *msg, int priority);
void jabber_presence_parse(JabberStream *js, xmlnode *packet);
void jabber_presence_subscription_set(JabberStream *js, const char *who,
		const char *type);
void jabber_presence_fake_to_self(JabberStream *js, PurpleStatus *status);
void purple_status_to_jabber(const PurpleStatus *status, JabberBuddyState *state, char **msg, int *priority);

#endif /* PURPLE_JABBER_PRESENCE_H_ */
