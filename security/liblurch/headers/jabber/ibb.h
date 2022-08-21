/*
 * purple - Jabber Service Discovery
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
 *
 */

#ifndef PURPLE_JABBER_IBB_H_
#define PURPLE_JABBER_IBB_H_

#include "jabber.h"
#include "iq.h"

typedef struct _JabberIBBSession JabberIBBSession;

typedef void
(JabberIBBDataCallback)(JabberIBBSession *, const gpointer data, gsize size);

typedef void (JabberIBBOpenedCallback)(JabberIBBSession *);
typedef void (JabberIBBClosedCallback)(JabberIBBSession *);
typedef void (JabberIBBErrorCallback)(JabberIBBSession *);
typedef void (JabberIBBSentCallback)(JabberIBBSession *);

typedef gboolean (JabberIBBOpenHandler)(JabberStream *js, const char *from,
                                        const char *id, xmlnode *open);

typedef enum {
	JABBER_IBB_SESSION_NOT_OPENED,
	JABBER_IBB_SESSION_OPENED,
	JABBER_IBB_SESSION_CLOSED,
	JABBER_IBB_SESSION_ERROR
} JabberIBBSessionState;

struct _JabberIBBSession {
	JabberStream *js;
	gchar *who;
	gchar *sid;
	gchar *id;
	guint16 send_seq;
	guint16 recv_seq;
	gsize block_size;

	/* session state */
	JabberIBBSessionState state;

	/* user data (f.ex. a handle to a PurpleXfer) */
	gpointer user_data;

	/* callbacks */
	JabberIBBOpenedCallback *opened_cb;
	JabberIBBSentCallback *data_sent_cb;
	JabberIBBClosedCallback *closed_cb;
	/* callback for receiving data */
	JabberIBBDataCallback *data_received_cb;
	JabberIBBErrorCallback *error_cb;

	/* store the last sent IQ (to permit cancel of callback) */
	gchar *last_iq_id;
};

JabberIBBSession *jabber_ibb_session_create(JabberStream *js, const gchar *sid,
	const gchar *who, gpointer user_data);
JabberIBBSession *jabber_ibb_session_create_from_xmlnode(JabberStream *js,
	const gchar *from, const gchar *id, xmlnode *open, gpointer user_data);

void jabber_ibb_session_destroy(JabberIBBSession *sess);

void jabber_ibb_session_set_opened_callback(JabberIBBSession *sess,
	JabberIBBOpenedCallback *cb);
void jabber_ibb_session_set_data_sent_callback(JabberIBBSession *sess,
	JabberIBBSentCallback *cb);
void jabber_ibb_session_set_closed_callback(JabberIBBSession *sess,
	JabberIBBClosedCallback *cb);
void jabber_ibb_session_set_data_received_callback(JabberIBBSession *sess,
	JabberIBBDataCallback *cb);
void jabber_ibb_session_set_error_callback(JabberIBBSession *sess,
	JabberIBBErrorCallback *cb);

void jabber_ibb_session_open(JabberIBBSession *sess);
void jabber_ibb_session_close(JabberIBBSession *sess);
void jabber_ibb_session_accept(JabberIBBSession *sess);
void jabber_ibb_session_send_data(JabberIBBSession *sess, gconstpointer data,
	gsize size);

const gchar *jabber_ibb_session_get_sid(const JabberIBBSession *sess);
JabberStream *jabber_ibb_session_get_js(JabberIBBSession *sess);
const gchar *jabber_ibb_session_get_who(const JabberIBBSession *sess);

guint16 jabber_ibb_session_get_send_seq(const JabberIBBSession *sess);
guint16 jabber_ibb_session_get_recv_seq(const JabberIBBSession *sess);

JabberIBBSessionState jabber_ibb_session_get_state(const JabberIBBSession *sess);

gsize jabber_ibb_session_get_block_size(const JabberIBBSession *sess);
void jabber_ibb_session_set_block_size(JabberIBBSession *sess, gsize size);

/* get maximum size data block to send (in bytes)
 (before encoded to BASE64) */
gsize jabber_ibb_session_get_max_data_size(const JabberIBBSession *sess);

gpointer jabber_ibb_session_get_user_data(JabberIBBSession *sess);

/* handle incoming packet */
void jabber_ibb_parse(JabberStream *js, const char *who, JabberIqType type,
                      const char *id, xmlnode *child);

/* add a handler for open session */
void jabber_ibb_register_open_handler(JabberIBBOpenHandler *cb);
void jabber_ibb_unregister_open_handler(JabberIBBOpenHandler *cb);

void jabber_ibb_init(void);
void jabber_ibb_uninit(void);

#endif /* PURPLE_JABBER_IBB_H_ */
