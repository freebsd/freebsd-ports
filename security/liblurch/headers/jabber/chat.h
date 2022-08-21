/**
 * @file chat.h Chat stuff
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
#ifndef PURPLE_JABBER_CHAT_H_
#define PURPLE_JABBER_CHAT_H_

//#include "internal.h"
#include "connection.h"
#include "conversation.h"
#include "request.h"
#include "roomlist.h"

#include "jabber.h"

typedef struct _JabberChatMember {
	char *handle;
	char *jid;
} JabberChatMember;


typedef struct _JabberChat {
	JabberStream *js;
	char *room;
	char *server;
	char *handle;
	GHashTable *components;
	int id;
	PurpleConversation *conv;
	gboolean muc;
	gboolean xhtml;
	PurpleRequestType config_dialog_type;
	void *config_dialog_handle;
	GHashTable *members;
	gboolean left;
	time_t joined;
} JabberChat;

GList *jabber_chat_info(PurpleConnection *gc);
GHashTable *jabber_chat_info_defaults(PurpleConnection *gc, const char *chat_name);
char *jabber_get_chat_name(GHashTable *data);

/**
 * in-prpl function for joining a chat room. Doesn't require sticking goop
 * into a hash table.
 *
 * @param room     The room to join. This MUST be normalized already.
 * @param server   The server the room is on. This MUST be normalized already.
 * @param password The password (if required) to join the room. May be NULL.
 * @param data     The chat hash table.  May be NULL (it will be generated
 *                 for current core<>prpl API interface.)
 */
JabberChat *jabber_join_chat(JabberStream *js, const char *room,
                             const char *server, const char *handle,
                             const char *password, GHashTable *data);

void jabber_chat_join(PurpleConnection *gc, GHashTable *data);
JabberChat *jabber_chat_find(JabberStream *js, const char *room,
		const char *server);
JabberChat *jabber_chat_find_by_id(JabberStream *js, int id);
JabberChat *jabber_chat_find_by_conv(PurpleConversation *conv);
void jabber_chat_destroy(JabberChat *chat);
void jabber_chat_free(JabberChat *chat);
gboolean jabber_chat_find_buddy(PurpleConversation *conv, const char *name);
void jabber_chat_invite(PurpleConnection *gc, int id, const char *message,
		const char *name);
void jabber_chat_leave(PurpleConnection *gc, int id);
char *jabber_chat_buddy_real_name(PurpleConnection *gc, int id, const char *who);
void jabber_chat_request_room_configure(JabberChat *chat);
void jabber_chat_create_instant_room(JabberChat *chat);
void jabber_chat_register(JabberChat *chat);
void jabber_chat_change_topic(JabberChat *chat, const char *topic);
void jabber_chat_set_topic(PurpleConnection *gc, int id, const char *topic);
gboolean jabber_chat_change_nick(JabberChat *chat, const char *nick);
void jabber_chat_part(JabberChat *chat, const char *msg);
void jabber_chat_track_handle(JabberChat *chat, const char *handle,
		const char *jid, const char *affiliation, const char *role);
void jabber_chat_remove_handle(JabberChat *chat, const char *handle);
gboolean jabber_chat_ban_user(JabberChat *chat, const char *who,
		const char *why);
gboolean jabber_chat_affiliate_user(JabberChat *chat, const char *who,
		const char *affiliation);
gboolean jabber_chat_affiliation_list(JabberChat *chat, const char *affiliation);
gboolean jabber_chat_role_user(JabberChat *chat, const char *who,
		const char *role, const char *why);
gboolean jabber_chat_role_list(JabberChat *chat, const char *role);

PurpleRoomlist *jabber_roomlist_get_list(PurpleConnection *gc);
void jabber_roomlist_cancel(PurpleRoomlist *list);

void jabber_chat_disco_traffic(JabberChat *chat);

char *jabber_roomlist_room_serialize(PurpleRoomlistRoom *room);

gboolean jabber_chat_all_participants_have_capability(const JabberChat *chat,
	const gchar *cap);
guint jabber_chat_get_num_participants(const JabberChat *chat);

#endif /* PURPLE_JABBER_CHAT_H_ */
