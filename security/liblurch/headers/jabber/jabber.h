/**
 * @file jabber.h
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
#ifndef PURPLE_JABBER_H_
#define PURPLE_JABBER_H_

typedef enum {
	JABBER_CAP_NONE           = 0,
/*	JABBER_CAP_XHTML          = 1 << 0, */
/*	JABBER_CAP_COMPOSING      = 1 << 1, */
	JABBER_CAP_SI             = 1 << 2,
	JABBER_CAP_SI_FILE_XFER   = 1 << 3,
	JABBER_CAP_BYTESTREAMS    = 1 << 4,
	JABBER_CAP_IBB            = 1 << 5,
	JABBER_CAP_CHAT_STATES    = 1 << 6,
	JABBER_CAP_IQ_SEARCH      = 1 << 7,
	JABBER_CAP_IQ_REGISTER    = 1 << 8,

	/* Google Talk extensions:
	 * http://code.google.com/apis/talk/jep_extensions/extensions.html
	 */
	JABBER_CAP_GMAIL_NOTIFY   = 1 << 9,
	JABBER_CAP_GOOGLE_ROSTER  = 1 << 10,

	JABBER_CAP_PING			  = 1 << 11,
	JABBER_CAP_ADHOC		  = 1 << 12,
	JABBER_CAP_BLOCKING       = 1 << 13,

	JABBER_CAP_ITEMS          = 1 << 14,
	JABBER_CAP_ROSTER_VERSIONING = 1 << 15,

	JABBER_CAP_FACEBOOK       = 1 << 16,

	JABBER_CAP_RETRIEVED      = 1 << 31
} JabberCapabilities;

typedef struct _JabberStream JabberStream;

#include <libxml/parser.h>
#include <glib.h>
#include "circbuffer.h"
#include "connection.h"
#include "dnsquery.h"
#include "dnssrv.h"
#include "media.h"
#include "mediamanager.h"
#include "roomlist.h"
#include "sslconn.h"

#include "namespaces.h"

#include "auth.h"
#include "iq.h"
#include "jutil.h"
#include "xmlnode.h"
#include "buddy.h"
#include "bosh.h"

#ifdef HAVE_CYRUS_SASL
#include <sasl/sasl.h>
#endif

#define CAPS0115_NODE "http://pidgin.im/"

#define JABBER_DEFAULT_REQUIRE_TLS    "require_starttls"
#define JABBER_DEFAULT_FT_PROXIES     "proxy.eu.jabber.org"

/* Index into attention_types list */
#define JABBER_BUZZ 0

typedef enum {
	JABBER_STREAM_OFFLINE,
	JABBER_STREAM_CONNECTING,
	JABBER_STREAM_INITIALIZING,
	JABBER_STREAM_INITIALIZING_ENCRYPTION,
	JABBER_STREAM_AUTHENTICATING,
	JABBER_STREAM_POST_AUTH,
	JABBER_STREAM_CONNECTED
} JabberStreamState;

struct _JabberStream
{
	int fd;

	PurpleSrvTxtQueryData *srv_query_data;

	xmlParserCtxt *context;
	xmlnode *current;

	struct {
		guint8 major;
		guint8 minor;
	} protocol_version;

	JabberSaslMech *auth_mech;
	gpointer auth_mech_data;

	/**
	 * The header from the opening <stream/> tag.  This being NULL is treated
	 * as a special condition in the parsing code (signifying the next
	 * stanza started is an opening stream tag), and its being missing on
	 * the stream header is treated as a fatal error.
	 */
	char *stream_id;
	JabberStreamState state;

	GHashTable *buddies;

	/*
	 * This boolean was added to eliminate a heinous bug where we would
	 * get into a loop with the server and move a buddy back and forth
	 * from one group to another.
	 *
	 * The sequence goes something like this:
	 * 1. Our resource and another resource both approve an authorization
	 *    request at the exact same time.  We put the buddy in group A and
	 *    the other resource put the buddy in group B.
	 * 2. The server receives the roster add for group B and sends us a
	 *    roster push.
	 * 3. We receive this roster push and modify our local blist.  This
	 *    triggers us to send a roster add for group B.
	 * 4. The server recieves our earlier roster add for group A and sends
	 *    us a roster push.
	 * 5. We receive this roster push and modify our local blist.  This
	 *    triggers us to send a roster add for group A.
	 * 6. The server receives our earlier roster add for group B and sends
	 *    us a roster push.
	 * (repeat steps 3 through 6 ad infinitum)
	 *
	 * This boolean is used to short-circuit the sending of a roster add
	 * when we receive a roster push.
	 *
	 * See these bug reports:
	 * http://trac.adiumx.com/ticket/8834
	 * http://developer.pidgin.im/ticket/5484
	 * http://developer.pidgin.im/ticket/6188
	 */
	gboolean currently_parsing_roster_push;

	GHashTable *chats;
	GList *chat_servers;
	PurpleRoomlist *roomlist;
	GList *user_directories;

	GHashTable *iq_callbacks;
	int next_id;

	GList *bs_proxies;
	GList *oob_file_transfers;
	GList *file_transfers;

	time_t idle;
	time_t old_idle;

	/** When we last pinged the server, so we don't ping more
	 *  often than once every minute.
	 */
	time_t last_ping;

	JabberID *user;
	JabberBuddy *user_jb;

	PurpleConnection *gc;
	PurpleSslConnection *gsc;

	gboolean registration;

	char *initial_avatar_hash;
	char *avatar_hash;
	GSList *pending_avatar_requests;

	GSList *pending_buddy_info_requests;

	PurpleCircBuffer *write_buffer;
	guint writeh;

	gboolean reinit;

	JabberCapabilities server_caps;
	gboolean googletalk;
	char *server_name;

	char *gmail_last_time;
	char *gmail_last_tid;

	char *serverFQDN;

#ifdef HAVE_CYRUS_SASL
	sasl_conn_t *sasl;
	sasl_callback_t *sasl_cb;
	sasl_secret_t *sasl_secret;
	const char *current_mech;
	int auth_fail_count;

	int sasl_state;
	int sasl_maxbuf;
	GString *sasl_mechs;
#endif

	gboolean unregistration;
	PurpleAccountUnregistrationCb unregistration_cb;
	void *unregistration_user_data;

	gboolean vcard_fetched;
	/* Timer at login to push updated avatar */
	guint vcard_timer;

	/* Entity Capabilities hash */
	char *caps_hash;

	/* does the local server support PEP? */
	gboolean pep;

	/* Is Buzz enabled? */
	gboolean allowBuzz;

	/* A list of JabberAdHocCommands supported by the server */
	GList *commands;

	/* last presence update to check for differences */
	JabberBuddyState old_state;
	char *old_msg;
	int old_priority;
	char *old_avatarhash;

	/* same for user tune */
	char *old_artist;
	char *old_title;
	char *old_source;
	char *old_uri;
	int old_length;
	char *old_track;

	char *certificate_CN;

	/* A purple timeout tag for the keepalive */
	guint keepalive_timeout;
	guint max_inactivity;
	guint inactivity_timer;

	PurpleSrvResponse *srv_rec;
	guint srv_rec_idx;
	guint max_srv_rec_idx;

	/* BOSH stuff */
	PurpleBOSHConnection *bosh;

	/**
	 * This linked list contains PurpleUtilFetchUrlData structs
	 * for when we lookup buddy icons from a url
	 */
	GSList *url_datas;

	/* keep a hash table of JingleSessions */
	GHashTable *sessions;

	/* maybe this should only be present when USE_VV? */
	gchar *stun_ip;
	int stun_port;
	PurpleDnsQueryData *stun_query;

	/* stuff for Google's relay handling */
	gchar *google_relay_token;
	gchar *google_relay_host;
	GList *google_relay_requests; /* the HTTP requests to get */
												/* relay info */

	/* facebook quirks */
	gboolean facebook_roster_cleanup_performed;
};

typedef gboolean (JabberFeatureEnabled)(JabberStream *js, const gchar *namespace);

typedef struct _JabberFeature
{
	gchar *namespace;
	JabberFeatureEnabled *is_enabled;
} JabberFeature;

typedef struct _JabberIdentity
{
	gchar *category;
	gchar *type;
	gchar *name;
	gchar *lang;
} JabberIdentity;

typedef struct _JabberBytestreamsStreamhost {
	char *jid;
	char *host;
	int port;
	char *zeroconf;
} JabberBytestreamsStreamhost;

/* what kind of additional features as returned from disco#info are supported? */
extern GList *jabber_features;
/* A sorted list of identities advertised.  Use jabber_add_identity to add
 * so it remains sorted.
 */
extern GList *jabber_identities;

void jabber_stream_features_parse(JabberStream *js, xmlnode *packet);
void jabber_process_packet(JabberStream *js, xmlnode **packet);
void jabber_send(JabberStream *js, xmlnode *data);
void jabber_send_raw(JabberStream *js, const char *data, int len);
void jabber_send_signal_cb(PurpleConnection *pc, xmlnode **packet,
                           gpointer unused);

void jabber_stream_set_state(JabberStream *js, JabberStreamState state);

void jabber_register_parse(JabberStream *js, const char *from,
                           JabberIqType type, const char *id, xmlnode *query);
void jabber_register_start(JabberStream *js);

char *jabber_get_next_id(JabberStream *js);

/** Parse an error into a human-readable string and optionally a disconnect
 *  reason.
 *  @param js     the stream on which the error occurred.
 *  @param packet the error packet
 *  @param reason where to store the disconnection reason, or @c NULL if you
 *                don't care or you don't intend to close the connection.
 */
char *jabber_parse_error(JabberStream *js, xmlnode *packet, PurpleConnectionError *reason);

/**
 * Add a feature to the list of features advertised via disco#info.  If you
 * call this while accounts are connected, Bad Things(TM) will happen because
 * the Entity Caps hash will be out-of-date (which should be fixed :/)
 *
 * @param namespace The namespace of the feature
 * @param cb        A callback determining whether or not this feature
 *                  will advertised; may be NULL.
 */
void jabber_add_feature(const gchar *namespace, JabberFeatureEnabled cb);
void jabber_remove_feature(const gchar *namespace);

/** Adds an identity to this jabber library instance. For list of valid values
 * visit the website of the XMPP Registrar
 * (http://www.xmpp.org/registrar/disco-categories.html#client).
 *
 * Like with jabber_add_feature, if you call this while accounts are connected,
 * Bad Things will happen.
 *
 *  @param category the category of the identity.
 *  @param type the type of the identity.
 *  @param language the language localization of the name. Can be NULL.
 *  @param name the name of the identity.
 */
void jabber_add_identity(const gchar *category, const gchar *type, const gchar *lang, const gchar *name);

/**
 * GCompareFunc for JabberIdentity structs.
 */
gint jabber_identity_compare(gconstpointer a, gconstpointer b);

/**
 * Returns true if this connection is over a secure (SSL) stream. Use this
 * instead of checking js->gsc because BOSH stores its PurpleSslConnection
 * members in its own data structure.
 */
gboolean jabber_stream_is_ssl(JabberStream *js);

/**
 * Restart the "we haven't sent anything in a while and should send
 * something or the server will kick us off" timer (obviously
 * called when sending something.  It's exposed for BOSH.)
 */
void jabber_stream_restart_inactivity_timer(JabberStream *js);

/** PRPL functions */
const char *jabber_list_icon(PurpleAccount *a, PurpleBuddy *b);
const char* jabber_list_emblem(PurpleBuddy *b);
char *jabber_status_text(PurpleBuddy *b);
void jabber_tooltip_text(PurpleBuddy *b, PurpleNotifyUserInfo *user_info, gboolean full);
GList *jabber_status_types(PurpleAccount *account);
void jabber_login(PurpleAccount *account);
void jabber_close(PurpleConnection *gc);
void jabber_idle_set(PurpleConnection *gc, int idle);
void jabber_blocklist_parse_push(JabberStream *js, const char *from,
                                 JabberIqType type, const char *id,
                                 xmlnode *child);
void jabber_request_block_list(JabberStream *js);
void jabber_add_deny(PurpleConnection *gc, const char *who);
void jabber_rem_deny(PurpleConnection *gc, const char *who);
void jabber_keepalive(PurpleConnection *gc);
void jabber_register_gateway(JabberStream *js, const char *gateway);
void jabber_register_account(PurpleAccount *account);
void jabber_unregister_account(PurpleAccount *account, PurpleAccountUnregistrationCb cb, void *user_data);
gboolean jabber_send_attention(PurpleConnection *gc, const char *username, guint code);
GList *jabber_attention_types(PurpleAccount *account);
void jabber_convo_closed(PurpleConnection *gc, const char *who);
PurpleChat *jabber_find_blist_chat(PurpleAccount *account, const char *name);
gboolean jabber_offline_message(const PurpleBuddy *buddy);
int jabber_prpl_send_raw(PurpleConnection *gc, const char *buf, int len);
GList *jabber_actions(PurplePlugin *plugin, gpointer context);

gboolean jabber_audio_enabled(JabberStream *js, const char *unused);
gboolean jabber_video_enabled(JabberStream *js, const char *unused);
gboolean jabber_initiate_media(PurpleAccount *account, const char *who,
		PurpleMediaSessionType type);
PurpleMediaCaps jabber_get_media_caps(PurpleAccount *account, const char *who);
gboolean jabber_can_receive_file(PurpleConnection *gc, const gchar *who);

void jabber_plugin_init(PurplePlugin *plugin);
void jabber_plugin_uninit(PurplePlugin *plugin);

#endif /* PURPLE_JABBER_H_ */
