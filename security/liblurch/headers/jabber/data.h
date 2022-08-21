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

#ifndef PURPLE_JABBER_DATA_H
#define PURPLE_JABBER_DATA_H

#include "xmlnode.h"
#include "jabber.h"

#include <glib.h>

#define JABBER_DATA_MAX_SIZE 8192


typedef struct {
	char *cid;
	char *type;
	gsize size;
	gpointer data;
	gboolean ephemeral;
} JabberData;

typedef void (JabberDataRequestCallback)(JabberData *data, gchar *alt,
    gpointer userdata);


/* creates a JabberData instance from raw data */
JabberData *jabber_data_create_from_data(gconstpointer data, gsize size,
	const char *type, gboolean ephemeral, JabberStream *js);

/* create a JabberData instance from an XML "data" element (as defined by
  XEP 0231 */
JabberData *jabber_data_create_from_xml(xmlnode *tag);

/* destroy a JabberData instance, NOT to be used on data that has been
	associated, since they get "owned" */
void jabber_data_destroy(JabberData *data);

const char *jabber_data_get_cid(const JabberData *data);
const char *jabber_data_get_type(const JabberData *data);

gsize jabber_data_get_size(const JabberData *data);
gpointer jabber_data_get_data(const JabberData *data);

/* returns the XML definition for the data element */
xmlnode *jabber_data_get_xml_definition(const JabberData *data);

/* returns an XHTML-IM "img" tag given a data instance */
xmlnode *jabber_data_get_xhtml_im(const JabberData *data, const gchar *alt);

void jabber_data_request(JabberStream *js, const gchar *cid, const gchar *who,
    gchar *alt, gboolean ephemeral, JabberDataRequestCallback cb,
    gpointer userdata);

/* lookup functions */
const JabberData *jabber_data_find_local_by_alt(const gchar *alt);
const JabberData *jabber_data_find_local_by_cid(const gchar *cid);
const JabberData *jabber_data_find_remote_by_cid(JabberStream *js,
    const gchar *who, const gchar *cid);

/* store data objects */
void jabber_data_associate_local(JabberData *data, const gchar *alt);
void jabber_data_associate_remote(JabberStream *js, const gchar *who,
    JabberData *data);

/* handles iq requests */
void jabber_data_parse(JabberStream *js, const char *who, JabberIqType type,
                       const char *id, xmlnode *data_node);

void jabber_data_init(void);
void jabber_data_uninit(void);

#endif /* PURPLE_JABBER_DATA_H */
