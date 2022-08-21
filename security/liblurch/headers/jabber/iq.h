/**
 * @file iq.h JabberID handlers
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
#ifndef PURPLE_JABBER_IQ_H_
#define PURPLE_JABBER_IQ_H_

typedef enum {
	JABBER_IQ_SET,
	JABBER_IQ_GET,
	JABBER_IQ_RESULT,
	JABBER_IQ_ERROR,
	JABBER_IQ_NONE
} JabberIqType;

#include "jabber.h"
#include "connection.h"

typedef struct _JabberIq JabberIq;
typedef struct _JabberIqCallbackData  JabberIqCallbackData;

/**
 * A JabberIqHandler is called to process an incoming IQ stanza.
 * Handlers typically process unsolicited incoming GETs or SETs for their
 * registered namespace, but may be called to handle the results of a
 * GET or SET that we generated if no JabberIqCallback was generated
 * The handler may be called for the results of a GET or SET (RESULT or ERROR)
 * that we generated
 * if the generating function did not register a JabberIqCallback.
 *
 * @param js    The JabberStream object.
 * @param from  The remote entity (the from attribute on the <iq/> stanza)
 * @param type  The IQ type.
 * @param id    The IQ id (the id attribute on the <iq/> stanza)
 * @param child The child element of the <iq/> stanza that matches the name
 *              and namespace registered with jabber_iq_register_handler.
 *
 * @see jabber_iq_register_handler()
 * @see JabberIqCallback
 */
typedef void (JabberIqHandler)(JabberStream *js, const char *from,
                               JabberIqType type, const char *id,
                               xmlnode *child);

/**
 * A JabberIqCallback is called to process the results of a GET or SET that
 * we send to a remote entity. The callback is matched based on the id
 * of the incoming stanza (which matches the one on the initial stanza).
 *
 * @param js     The JabberStream object.
 * @param from   The remote entity (the from attribute on the <iq/> stanza)
 * @param type   The IQ type. The only possible values are JABBER_IQ_RESULT
 *               and JABBER_IQ_ERROR.
 * @param id     The IQ id (the id attribute on the <iq/> stanza)
 * @param packet The <iq/> stanza
 * @param data   The callback data passed to jabber_iq_set_callback()
 *
 * @see jabber_iq_set_callback()
 */
typedef void (JabberIqCallback)(JabberStream *js, const char *from,
                                JabberIqType type, const char *id,
                                xmlnode *packet, gpointer data);

struct _JabberIq {
	JabberIqType type;
	char *id;
	xmlnode *node;

	JabberIqCallback *callback;
	gpointer callback_data;

	JabberStream *js;
};

JabberIq *jabber_iq_new(JabberStream *js, JabberIqType type);
JabberIq *jabber_iq_new_query(JabberStream *js, JabberIqType type,
		const char *xmlns);

void jabber_iq_parse(JabberStream *js, xmlnode *packet);

void jabber_iq_callbackdata_free(JabberIqCallbackData *jcd);
void jabber_iq_remove_callback_by_id(JabberStream *js, const char *id);
void jabber_iq_set_callback(JabberIq *iq, JabberIqCallback *cb, gpointer data);
void jabber_iq_set_id(JabberIq *iq, const char *id);

void jabber_iq_send(JabberIq *iq);
void jabber_iq_free(JabberIq *iq);

void jabber_iq_init(void);
void jabber_iq_uninit(void);

void jabber_iq_register_handler(const char *node, const char *xmlns,
                                JabberIqHandler *func);

/* Connected to namespace-handler registration signals */
void jabber_iq_signal_register(const gchar *node, const gchar *xmlns);
void jabber_iq_signal_unregister(const gchar *node, const gchar *xmlns);

#endif /* PURPLE_JABBER_IQ_H_ */
