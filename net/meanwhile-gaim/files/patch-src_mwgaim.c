--- src/mwgaim.c	Tue Jun  1 19:29:17 2004
+++ src/mwgaim.c	Wed Jun 23 03:53:08 2004
@@ -1,24 +1,23 @@
 
-/*
-Meanwhile Gaim Protocol Plugin (prpl). Adds Lotus Sametime support to Gaim.
+/* Meanwhile Gaim Protocol Plugin (prpl). Adds Lotus Sametime support
+to Gaim.
 
-Copyright (C) 2004 Christopher (siege) O'Brien <obriencj@us.ibm.com>
-Copyright (C) 2004 IBM Corporation
+Copyright (C) 2004 Christopher (siege) O'Brien <siege@preoccupied.net>
 
-This program is free software; you can redistribute it and/or
-modify it under the terms of the GNU General Public License
-as published by the Free Software Foundation; either version 2
-of the License, or (at your option) any later version.
-
-This program is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+This program is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2 of the License, or (at
+your option) any later version.
+
+This program is distributed in the hope that it will be useful, but
+WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
+General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
-Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
-*/
+Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
+USA. */
 
 
 #define GAIM_PLUGINS
@@ -41,10 +40,75 @@
 #include <meanwhile/srvc_aware.h>
 #include <meanwhile/srvc_conf.h>
 #include <meanwhile/srvc_im.h>
+#include <meanwhile/srvc_store.h>
+#include <meanwhile/st_list.h>
 
-#include "mwgaim.h"
+
+/* considering that there's no display of this information for prpls,
+   I don't know why I even bother providing these. Oh valiant reader,
+   I do it all for you. */
+#define PLUGIN_ID        "prpl-meanwhile"
+#define PLUGIN_NAME      "Meanwhile"
+#define PLUGIN_SUMMARY   "Meanwhile Protocol Plugin"
+#define PLUGIN_DESC      "Open implementation of a Lotus Sametime client"
+#define PLUGIN_AUTHOR    "Christopher (siege) O'Brien <siege@preoccupied.net>"
+#define PLUGIN_HOMEPAGE  "http://meanwhile.sf.net/"
+
+#define MW_CONNECT_STEPS  7
+#define MW_CONNECT_1  _("Looking up server")
+#define MW_CONNECT_2  _("Sending Handshake")
+#define MW_CONNECT_3  _("Waiting for Handshake Acknowledgement")
+#define MW_CONNECT_4  _("Handshake Acknowledged, Sending Login")
+#define MW_CONNECT_5  _("Waiting for Login Acknowledgement")
+#define MW_CONNECT_6  _("Login Acknowledged")
+
+#define UC_NORMAL  0x10
+
+#define MW_STATE_OFFLINE  _("Offline")
+#define MW_STATE_ACTIVE   _("Active")
+#define MW_STATE_AWAY     _("Away")
+#define MW_STATE_BUSY     _("Do Not Disturb")
+#define MW_STATE_IDLE     _("Idle")
+#define MW_STATE_UNKNOWN  _("Unknown")
+
+
+/* keys to get/set chat information */
+#define CHAT_CREATOR_KEY  "chat_creator"
+#define CHAT_NAME_KEY     "chat_name"
+#define CHAT_TOPIC_KEY    "chat_topic"
+#define CHAT_INVITE_KEY   "chat_invite"
+
+
+/* keys to get/set gaim plugin information */
+#define MW_KEY_HOST       "server"
+#define MW_KEY_PORT       "port"
+
+
+/** default host for the gaim plugin. You can specialize a build to
+    default to your server by supplying this at compile time */
+#ifndef PLUGIN_DEFAULT_HOST
+#define PLUGIN_DEFAULT_HOST       ""
+#endif
+
+
+/** default port for the gaim plugin. You can specialize a build to
+    default to your server by supplying this at compile time */
+#ifndef PLUGIN_DEFAULT_PORT
+#define PLUGIN_DEFAULT_PORT       1533
+#endif
+
+
+/** the amount of data the plugin will attempt to read from a socket
+    in a single call */
+#define READ_BUFFER_SIZE  1024
+
+
+/** default inactivity threshold for the gaim plugin to pass to
+    mwChannel_destroyInactive. length in seconds */
+#define INACTIVE_THRESHOLD 30
 
 
+/* there's probably a better way, I just never bothered finding it */
 #ifndef os_write
 # ifndef _WIN32
 #  define os_write(fd, buffer, len) write(fd, buffer, len)
@@ -54,6 +118,7 @@
 #endif
 
 
+/* there's probably a better way, I just never bothered finding it */
 #ifndef os_read
 # ifndef _WIN32
 #  define os_read(fd, buffer, size) read(fd, buffer, size)
@@ -63,6 +128,7 @@
 #endif
 
 
+/* there's probably a better way, I just never bothered finding it */
 #ifndef os_close
 # ifndef _WIN32
 #  define os_close(fd) close(fd)
@@ -72,34 +138,44 @@
 #endif
 
 
-#define DEBUG_ERROR(a)  gaim_debug_error(G_LOG_DOMAIN, a)
-#define DEBUG_INFO(a)   gaim_debug_info(G_LOG_DOMAIN, a)
-#define DEBUG_MISC(a)   gaim_debug_misc(G_LOG_DOMAIN, a)
-#define DEBUG_WARN(a)   gaim_debug_warning(G_LOG_DOMAIN, a)
+#define DEBUG_ERROR(a)  gaim_debug_error(G_LOG_DOMAIN, a "\n")
+#define DEBUG_INFO(a)   gaim_debug_info(G_LOG_DOMAIN, a "\n")
+#define DEBUG_MISC(a)   gaim_debug_misc(G_LOG_DOMAIN, a "\n")
+#define DEBUG_WARN(a)   gaim_debug_warning(G_LOG_DOMAIN, a "\n")
 
 
+/** get the mw_handler from a mwSession */
 #define SESSION_HANDLER(session) \
   ((struct mw_handler *) (session)->handler)
 
 
+/** get the mw_plugin_data from a GaimConnection */
 #define PLUGIN_DATA(gc) \
   ((struct mw_plugin_data *) (gc)->proto_data)
 
 
+/** get the mwSession from a GaimConnection */
 #define GC_TO_SESSION(gc) \
   ((PLUGIN_DATA(gc))->session)
 
 
+/** get the GaimConnection from a mwSession */
 #define SESSION_TO_GC(session) \
   ((SESSION_HANDLER(session))->gc)
 
 
 struct mw_plugin_data {
   struct mwSession *session;
-  struct mwServiceIM *srvc_im;
+
   struct mwServiceAware *srvc_aware;
+
   struct mwServiceConf *srvc_conf;
 
+  struct mwServiceIM *srvc_im;
+
+  struct mwServiceStorage *srvc_store;
+
+  GHashTable *list_map;
   GHashTable *convo_map;
 };
 
@@ -111,33 +187,29 @@
 };
 
 
-/* returns 0 if all bytes were written successfully, -1 for any sort of
-   failure. */
+/** returns 0 if all bytes were written successfully, -1 for any sort
+    of failure. */
 static int mw_handler_write(struct mwSessionHandler *this,
 			    const char *b, gsize n) {
 
   struct mw_handler *h = (struct mw_handler *) this;
-  int ret;
+  int ret = 0;
 
   while(n) {
-    /* this looks weird, but it's almost sane. I'm going from an unsigned int
-       length to a signed int length. The likely-hood of n ever being that
-       large is super-duper-minimal, but I don't like chances. So mask off the
-       sign bit and only write that many bytes at a time. The normal write
-       loop then continues writing until n is decremented to zero, or os_write
-       errors */
-    ret = os_write(h->sock_fd, b, (n & 0xefffffff));
+    ret = os_write(h->sock_fd, b, n);
     if(ret <= 0) break;
     n -= ret;
   }
 
-  if( (ret = n) ) {
+  if(n > 0) {
+    /* if there's data left over, something must have failed */
     gaim_debug_error(G_LOG_DOMAIN, "mw_handler_write returning %i\n", ret);
     gaim_connection_error(h->gc, "Connection died");
-    ret = -1;
-  }
+    return -1;
 
-  return ret;
+  } else {
+    return 0;
+  }
 }
 
 
@@ -169,18 +241,18 @@
     char buf[READ_BUFFER_SIZE];
     int len = READ_BUFFER_SIZE;
 
+    /* note, don't use gsize. len might be -1 */
+
     len = os_read(h->sock_fd, buf, len);
     if(len > 0) {
-      gaim_debug_info("meanwhile", "reading %u bytes\n", len);
+      gaim_debug_info(G_LOG_DOMAIN, "read %i bytes\n", len);
       mwSession_recv(session, buf, (unsigned int) len);
-
-    } else {
-      gaim_connection_destroy(gc);
+      return;
     }
-
-  } else {
-    gaim_connection_destroy(gc);
   }
+
+  /* fall-through indicates an error */
+  gaim_connection_destroy(gc);
 }
 
 
@@ -191,18 +263,14 @@
   struct mwSession *session = GC_TO_SESSION(gc);
   struct mw_handler *h;
 
-  DEBUG_INFO(" --> mw_login_callback\n");
-
   if(! g_list_find(gaim_connections_get_all(), data)) {
     os_close(source);
-    DEBUG_INFO(" <-- mw_login_callback (connection not found)\n");
-    return;
+    g_return_if_reached();
   }
 
   if(source < 0) {
     gaim_connection_error(gc, "Unable to connect");
-    DEBUG_ERROR(" unable to connect in mw_login_callback\n");
-    DEBUG_INFO(" <-- mw_login_callback (unable to connect)\n");
+    DEBUG_ERROR(" unable to connect in mw_login_callback");
     return;
   }
 
@@ -211,9 +279,7 @@
   session->handler = (struct mwSessionHandler *) h;
 
   gc->inpa = gaim_input_add(source, GAIM_INPUT_READ, mw_read_callback, gc);
-  mwSession_initConnect(session);
-
-  DEBUG_INFO(" <-- mw_login_callback\n");
+  mwSession_start(session);
 }
 
 
@@ -224,13 +290,14 @@
   g_return_if_fail(s);
 
   if(mw_handler_write(s->handler, &c, 1)) {
-    DEBUG_WARN("looks like keepalive byte failed\n");
+    DEBUG_WARN("looks like keepalive byte failed");
 
   } else {
-    /* close any OPEN or WAIT channels which have been inactive for
-       at least the INACTIVE_THRESHOLD seconds, but only if we're
-       still connected. */
-    mwChannelSet_destroyInactive(s->channels, time(NULL) - INACTIVE_THRESHOLD);
+    /* close any OPEN or WAIT channels which have been inactive for at
+       least the INACTIVE_THRESHOLD seconds, but only if we're still
+       connected. */
+    mwChannelSet_destroyInactive(s->channels,
+				 time(NULL) - INACTIVE_THRESHOLD);
   }
 }
 
@@ -238,19 +305,15 @@
 static void on_initConnect(struct mwSession *s) {
   GaimConnection *gc = SESSION_TO_GC(s);
 
-  DEBUG_INFO(" --> on_initConnect\n");
   gaim_connection_update_progress(gc, MW_CONNECT_2, 2, MW_CONNECT_STEPS);
-  initConnect_sendHandshake(s);
-  DEBUG_INFO(" <-- on_initConnect\n");
+  onStart_sendHandshake(s);
 }
 
 
 static void on_handshake(struct mwSession *s, struct mwMsgHandshake *msg) {
   GaimConnection *gc = SESSION_TO_GC(s);
 
-  DEBUG_INFO(" --> on_handshake\n");
   gaim_connection_update_progress(gc, MW_CONNECT_3, 3, MW_CONNECT_STEPS);
-  DEBUG_INFO(" <-- on_handshake\n");
 }
 
 
@@ -259,100 +322,186 @@
 
   GaimConnection *gc = SESSION_TO_GC(s);
 
-  DEBUG_INFO(" --> on_handshakeAck\n");
   gaim_connection_update_progress(gc, MW_CONNECT_4, 4, MW_CONNECT_STEPS);
-  handshakeAck_sendLogin(s, msg);
-  DEBUG_INFO(" <-- on_handshakeAck\n");
+  onHandshakeAck_sendLogin(s, msg);
 }
 
 
 static void on_login(struct mwSession *s, struct mwMsgLogin *msg) {
   GaimConnection *gc = SESSION_TO_GC(s);
 
-  DEBUG_INFO(" --> on_login\n");
   gaim_connection_update_progress(gc, MW_CONNECT_5, 5, MW_CONNECT_STEPS);
-  DEBUG_INFO(" <-- on_login\n");
+}
+
+
+static GaimGroup *ensure_group(GaimConnection *gc,
+			       struct mwSametimeGroup *stgroup) {
+  GaimGroup *group;
+  const char *name = mwSametimeGroup_getName(stgroup);
+
+  group = gaim_find_group(name);
+  if(! group) {
+    group = gaim_group_new(name);
+    gaim_blist_add_group(group, NULL);
+  }
+
+  return group;
+}
+
+
+static GaimBuddy *ensure_buddy(GaimConnection *gc, GaimGroup *group,
+			       struct mwSametimeUser *stuser) {
+
+  GaimBuddy *buddy;
+
+  GaimAccount *acct = gaim_connection_get_account(gc);
+
+  const char *name = mwSametimeUser_getUser(stuser);
+  const char *alias = mwSametimeUser_getAlias(stuser);
+
+  buddy = gaim_find_buddy_in_group(acct, name, group);
+  if(! buddy) {
+    buddy = gaim_buddy_new(acct, name, alias);
+    gaim_blist_add_buddy(buddy, NULL, group, NULL);
+    
+  }
+
+  return buddy;
+}
+
+
+static void import_blist(GaimConnection *gc, struct mwSametimeList *stlist) {
+  struct mwSametimeGroup *stgroup;
+  struct mwSametimeUser *stuser;
+
+  GaimGroup *group;
+  GaimBuddy *buddy;
+
+  GList *gl, *gtl, *ul, *utl;
+
+  gl = gtl = mwSametimeList_getGroups(stlist);
+  for(; gl; gl = gl->next) {
+
+    stgroup = (struct mwSametimeGroup *) gl->data;
+    group = ensure_group(gc, stgroup);
+
+    ul = utl = mwSametimeGroup_getUsers(stgroup);
+    for(; ul; ul = ul->next) {
+
+      stuser = (struct mwSametimeUser *) ul->data;
+      buddy = ensure_buddy(gc, group, stuser);
+    }
+    g_list_free(utl);
+  }
+  g_list_free(gtl);
+}
+
+
+static void storage_load_cb(struct mwServiceStorage *srvc, guint result,
+			    struct mwStorageUnit *item, gpointer dat) {
+
+  struct mwSametimeList *stlist;
+  char *b, *tmp;
+  gsize n;
+
+  g_message(" storage_cb, key = 0x%08x, result = 0x%08x, length = 0x%08x",
+	    item->key, result, item->data.len);
+
+  if(result) return;
+
+  b = tmp = mwStorageUnit_asString(item);
+  n = strlen(b);
+
+  if(! n) return;
+
+  stlist = mwSametimeList_new();
+  mwSametimeList_get(&b, &n, stlist);
+
+  import_blist(SESSION_TO_GC(mwService_getSession(MW_SERVICE(srvc))), stlist);
+
+  mwSametimeList_free(stlist);
+
+  /* no need to free the storage unit, that will happen automatically
+     after this callback */
+  g_free(tmp);
+}
+
+
+static void fetch_blist(struct mwServiceStorage *srvc) {
+  struct mwStorageUnit *unit = mwStorageUnit_new(mwStore_AWARE_LIST);
+  mwServiceStorage_load(srvc, unit, storage_load_cb, NULL);
 }
 
 
 static void on_loginAck(struct mwSession *s, struct mwMsgLoginAck *msg) {
   GaimConnection *gc = SESSION_TO_GC(s);
-  /* struct mwUserStatus stat = { mwStatus_ACTIVE, 0, NULL }; */
+  struct mw_plugin_data *pd = (struct mw_plugin_data *) gc->proto_data;
 
-  DEBUG_INFO(" --> on_loginAck\n");
   gaim_connection_update_progress(gc, MW_CONNECT_6, 6, MW_CONNECT_STEPS);
-
-  DEBUG_INFO(" 1\n");
   gaim_connection_set_state(gc, GAIM_CONNECTED);
-
-  DEBUG_INFO(" 2\n");
   serv_finish_login(gc);
 
-  /* Have to do this. Would be nicer if this happened in the session
-     code. */
-  /* DEBUG_INFO(" 3\n");
-     mwSession_setUserStatus(s, &stat); */
+  /* later this won't be necessary, as the session will auto-start
+     services on receipt of the service available message */
 
-  DEBUG_INFO(" <-- on_loginAck\n");
+  mwService_start(MW_SERVICE(pd->srvc_conf));
+  mwService_start(MW_SERVICE(pd->srvc_im));
+
+  mwService_start(MW_SERVICE(pd->srvc_store));
+  fetch_blist(pd->srvc_store);
+
+  /* do this last, otherwise the storage stuff won't receive initial
+     presence notification */
+  mwService_start(MW_SERVICE(pd->srvc_aware));
 }
 
 
 static void on_closeConnect(struct mwSession *session, guint32 reason) {
-
   GaimConnection *gc;
 
-  DEBUG_INFO(" --> on_closeConnect\n");
+  g_return_if_fail(SESSION_HANDLER(session));
 
-  if(SESSION_HANDLER(session)) {
-    gc = SESSION_TO_GC(session);
-    if(! gc) return;
-
-    if(reason & ERR_FAILURE) {
-      gchar *text = mwError(reason);
-      gaim_connection_error(gc, text);
-      g_free(text);
-
-    } else if(gc->inpa) {
-      /* remove the input checker, so that closing the socket won't be
-	 seen as an error, and won't trigger a re-connect */
-      gaim_input_remove(gc->inpa);
-      gc->inpa = 0;
-    }
-  }
+  gc = SESSION_TO_GC(session);
+  g_return_if_fail(gc);
 
-  DEBUG_INFO(" <-- on_closeConnect\n");
+  if(reason & ERR_FAILURE) {
+    gchar *text = mwError(reason);
+    gaim_connection_error(gc, text);
+    g_free(text);
+
+  } else if(gc->inpa) {
+    /* remove the input checker, so that closing the socket won't be
+       seen as an error, and won't trigger a re-connect */
+    gaim_input_remove(gc->inpa);
+    gc->inpa = 0;
+  }
 }
 
 
 static void on_setUserStatus(struct mwSession *s,
 			     struct mwMsgSetUserStatus *msg) {
 
-  /* this plugin allows the user to add themselves to their buddy list. the
-     server's aware service doesn't always honor that by sending updates back
-     to us. so we're going to ensure our status is updated by passing it back
-     to the aware service when we receive a SetUserStatus message */
+  /* this plugin allows the user to add themselves to their buddy
+     list. the server's aware service doesn't always honor that by
+     sending updates back to us. so we're going to ensure our status
+     is updated by passing it back to the aware service when we
+     receive a SetUserStatus message */
 
   GaimConnection *gc = SESSION_TO_GC(s);
   struct mw_plugin_data *pd = PLUGIN_DATA(gc);
   struct mwServiceAware *srvc = pd->srvc_aware;
 
   struct mwAwareIdBlock id = { mwAware_USER,
-			       s->login.user_id, s->login.community };
+			       s->login.user_id,
+			       s->login.community };
 
   mwServiceAware_setStatus(srvc, &id, &msg->status);
 }
 
 
 static void on_admin(struct mwSession *s, struct mwMsgAdmin *msg) {
-  DEBUG_INFO(" admin message:\n");
-  DEBUG_INFO(msg->text);
-
-  gaim_connection_notice(SESSION_TO_GC(s), msg->text);
-
-  /*
   gaim_notify_message(SESSION_TO_GC(s), GAIM_NOTIFY_MSG_INFO,
 		      _("Admin Alert"), msg->text, NULL, NULL, NULL);
-  */
 }
 
 
@@ -387,30 +536,32 @@
 
 
 static void got_typing(struct mwServiceIM *srvc,
-		       struct mwIdBlock *who, int typing) {
+		       struct mwIdBlock *who, gboolean typing) {
 
   /* if user@community split, compose buddy name */
 
   struct mwSession *s = srvc->service.session;
 
-  if(typing)
+  if(typing) {
     serv_got_typing(SESSION_TO_GC(s), who->user, 0, GAIM_TYPING);
-  else
-    serv_got_typing_stopped(SESSION_TO_GC(s), who->user);    
+  } else {
+    serv_got_typing_stopped(SESSION_TO_GC(s), who->user);
+  }
 }
 
 
-static void update_buddy(struct mwSession *s,
-			 struct mwSnapshotAwareIdBlock *idb) {
-
-  GaimConnection *gc = SESSION_TO_GC(s);
+static void got_aware(struct mwAwareList *list,
+		      struct mwSnapshotAwareIdBlock *idb, gpointer data) {
 
+  GaimConnection *gc = (GaimConnection *) data;
   time_t idle = 0;
-  /* unsigned int i = idb->status.time; */
 
-  /* deadbeef or 0 from the client means not idle (unless the status indicates
-     otherwise), but deadbeef to the blist causes idle with no time */
+  /* deadbeef or 0 from the client means not idle (unless the status
+     indicates otherwise), but deadbeef to the blist causes idle with
+     no time */
   /*
+  unsigned int i = idb->status.time;
+
   if( (idb->status.status == mwStatus_IDLE) ||
       ((i > 0) && (i != 0xdeadbeef)) ) {
 
@@ -418,7 +569,7 @@
   }
   */
 
-  /* over-riding idle times until fixed in a later release */
+  /* idle times unused until fixed in a later release */
   if(idb->status.status == mwStatus_IDLE)
     idle = -1;
 
@@ -427,28 +578,19 @@
 }
 
 
-static void got_aware(struct mwServiceAware *srvc,
-		      struct mwSnapshotAwareIdBlock *idb, unsigned int c) {
-
-  struct mwSession *s = srvc->service.session;
-  while(c--) update_buddy(s, idb + c);
-}
-
-
 static void got_invite(struct mwConference *conf, struct mwIdBlock *id,
 		       const char *text) {
 
   GaimConnection *gc;
   GHashTable *ht;
 
-  /* the trick here is that we want these strings cleaned up when we're done,
-     but not until then. When we return, the originals will be cleaned up. The
-     copies are in the hash table, so when the hash table goes, they'll be
-     free'd too. Just don't try to free the keys */
+  /* the trick here is that we want these strings cleaned up when
+     we're done, but not until then. When we return, the originals
+     will be cleaned up. The copies are in the hash table, so when the
+     hash table goes, they'll be free'd too. Just don't try to free
+     the keys */
   char *a, *b, *c, *d;
 
-  DEBUG_INFO(" --> got invite\n");
-
   gc = SESSION_TO_GC(conf->channel->session);
   ht = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, g_free);
 
@@ -462,14 +604,12 @@
   g_hash_table_insert(ht, CHAT_TOPIC_KEY, c);
   g_hash_table_insert(ht, CHAT_INVITE_KEY, d);
 
-  gaim_debug_info("meanwhile",
-		  "invitor: '%s', name: '%s', topic: '%s', text: '%s'\n",
+  gaim_debug_info(G_LOG_DOMAIN,
+		  "Got invite: '%s', name: '%s', topic: '%s', text: '%s'\n",
 		  a, b, c, d);
 
-  DEBUG_INFO(" triggering serv_got_invite\n");
+  DEBUG_INFO(" triggering serv_got_invite");
   serv_got_chat_invite(gc, c, a, d, ht);
-
-  DEBUG_INFO(" <-- got invite\n");
 }
 
 
@@ -480,7 +620,7 @@
   struct mw_plugin_data *pd = PLUGIN_DATA(gc);
   GaimConversation *conv;
 
-  DEBUG_INFO(" got welcome\n");
+  DEBUG_INFO(" got welcome");
 
   conv = serv_got_joined_chat(gc, conf->channel->id, conf->topic);
   gaim_conv_chat_set_id(GAIM_CONV_CHAT(conv), conf->channel->id);
@@ -500,7 +640,7 @@
   struct mw_plugin_data *pd = PLUGIN_DATA(gc);
   GaimConversation *conv;
 
-  DEBUG_INFO(" got closed\n");
+  DEBUG_INFO(" got closed");
 
   conv = (GaimConversation *) g_hash_table_lookup(pd->convo_map, conf);
 
@@ -516,10 +656,10 @@
   GaimConversation *conv;
 
   conv = (GaimConversation *) g_hash_table_lookup(pd->convo_map, conf);
-  if(conv) {
-    DEBUG_INFO(" got join\n");
-    gaim_conv_chat_add_user(GAIM_CONV_CHAT(conv), id->user, NULL);
-  }
+  g_return_if_fail(conv);
+
+  DEBUG_INFO(" got join");
+  gaim_conv_chat_add_user(GAIM_CONV_CHAT(conv), id->user, NULL);
 }
 
 
@@ -529,10 +669,10 @@
   GaimConversation *conv;
 
   conv = (GaimConversation *) g_hash_table_lookup(pd->convo_map, conf);
-  if(conv) {
-    DEBUG_INFO(" got part\n");
-    gaim_conv_chat_remove_user(GAIM_CONV_CHAT(conv), id->user, NULL);
-  }
+  g_return_if_fail(conv);
+
+  DEBUG_INFO(" got part");
+  gaim_conv_chat_remove_user(GAIM_CONV_CHAT(conv), id->user, NULL);
 }
 
 
@@ -544,18 +684,17 @@
   GaimConversation *conv;
 
   conv = (GaimConversation *) g_hash_table_lookup(pd->convo_map, conf);
-  if(conv) {
-    gaim_debug_info("meanwhile", " got conf text: '%s'\n", text);
-    serv_got_chat_in(gc, gaim_conv_chat_get_id(GAIM_CONV_CHAT(conv)),
-		     id->user, 0, text, time(NULL));
-  }
+  g_return_if_fail(conv);
+
+  serv_got_chat_in(gc, gaim_conv_chat_get_id(GAIM_CONV_CHAT(conv)),
+		   id->user, 0, text, time(NULL));
 }
 
 
 static void got_conf_typing(struct mwConference *conf, struct mwIdBlock *id,
-			    int typing) {
+			    gboolean typing) {
 
-  /* no gaim support for this?? oh no! */
+  ; /* no gaim support for this?? oh no! */
 }
 
 
@@ -567,11 +706,12 @@
   struct mwServiceAware *srvc_aware;
   struct mwServiceIM *srvc_im;
   struct mwServiceConf *srvc_conf;
+  struct mwServiceStorage *srvc_store;
   
   const char *host;
   unsigned int port;
 
-  DEBUG_INFO(" --> mw_login\n");
+  DEBUG_INFO(" --> mw_login");
 
   gc->proto_data = pd = g_new0(struct mw_plugin_data, 1);
 
@@ -581,31 +721,25 @@
   session->on_handshakeAck = on_handshakeAck;
   session->on_login = on_login;
   session->on_loginAck = on_loginAck;
-  session->on_initConnect = on_initConnect;
-  session->on_closeConnect = on_closeConnect;
+  session->on_start = on_initConnect;
+  session->on_stop = on_closeConnect;
   session->on_setUserStatus = on_setUserStatus;
   session->on_admin = on_admin;
 
-  /* user_id, community */
+  /* user_id, password */
   session->login.user_id = g_strdup(gaim_account_get_username(acct));
-  /* session->login.community =
-     g_strdup(gaim_account_get_string(acct, MW_KEY_COMMUNITY,
-     PLUGIN_DEFAULT_COMMUNITY)); */
-
-  /* password */
   session->auth.password = g_strdup(gaim_account_get_password(acct));
 
   /* aware service and call-backs */
   pd->srvc_aware = srvc_aware = mwServiceAware_new(session);
-  srvc_aware->got_aware = got_aware;
-  mwSession_putService(session, (struct mwService *) srvc_aware);
+  mwSession_putService(session, MW_SERVICE(srvc_aware));
 
   /* im service and call-backs */
   pd->srvc_im = srvc_im = mwServiceIM_new(session);
   srvc_im->got_error = got_error;
   srvc_im->got_text = got_text;
   srvc_im->got_typing = got_typing;
-  mwSession_putService(session, (struct mwService *) srvc_im);
+  mwSession_putService(session, MW_SERVICE(srvc_im));
 
   /* conference service and call-backs */
   pd->srvc_conf = srvc_conf = mwServiceConf_new(session);
@@ -616,9 +750,14 @@
   srvc_conf->got_part = got_part;
   srvc_conf->got_text = got_conf_text;
   srvc_conf->got_typing = got_conf_typing;
-  mwSession_putService(session, (struct mwService *) srvc_conf);
+  mwSession_putService(session, MW_SERVICE(srvc_conf));
 
   pd->convo_map = g_hash_table_new(NULL, NULL);
+  pd->list_map = g_hash_table_new(NULL, NULL);
+
+  /* storage service */
+  pd->srvc_store = srvc_store = mwServiceStorage_new(session);
+  mwSession_putService(session, MW_SERVICE(srvc_store));
 
   /* server:port */
   host = gaim_account_get_string(acct, "server", PLUGIN_DEFAULT_HOST);
@@ -629,7 +768,7 @@
   if(gaim_proxy_connect(acct, host, port, mw_login_callback, gc))
     gaim_connection_error(gc, "Unable to connect");
 
-  DEBUG_INFO(" <-- mw_login\n");  
+  DEBUG_INFO(" <-- mw_login");  
 }
 
 
@@ -637,26 +776,24 @@
   struct mwSession *session;
   struct mw_plugin_data *pd = PLUGIN_DATA(gc);
 
-  DEBUG_INFO(" --> mw_close\n"); 
-
-  if(pd) {
-    session = GC_TO_SESSION(gc);
+  g_return_if_fail(pd != NULL);
 
-    if(session) {
-      mwSession_closeConnect(session, ERR_SUCCESS);
+  session = pd->session;
+  if(session) {
+    mwSession_stop(session, ERR_SUCCESS);
 
-      /* we created it, so we need to clean it up */
-      g_free(session->handler);
-      session->handler = NULL;
-      mwSession_free(&session);
-    }
+    mwService_free(MW_SERVICE(pd->srvc_aware));
+    mwService_free(MW_SERVICE(pd->srvc_conf));
+    mwService_free(MW_SERVICE(pd->srvc_im));
+    mwService_free(MW_SERVICE(pd->srvc_store));
 
-    gc->proto_data = NULL;
-    g_hash_table_destroy(pd->convo_map);
-    g_free(pd);
+    g_free(session->handler);
+    mwSession_free(session);
   }
 
-  DEBUG_INFO(" <-- mw_close\n"); 
+  gc->proto_data = NULL;
+  g_hash_table_destroy(pd->convo_map);
+  g_free(pd);
 }
 
 
@@ -669,6 +806,9 @@
      careful to center it. Then, just change the color saturation to
      bring the red down a bit, and voila! */
 
+  /* then, throw all of that away and use sodipodi to make a new
+     icon. You know, LIKE A REAL MAN. */
+
   return "meanwhile";
 }
 
@@ -723,12 +863,13 @@
 
 
 static char *mw_list_status_text(GaimBuddy *b) {
-  g_return_val_if_fail(b, NULL);
+  GaimConnection *gc = b->account->gc;
+  struct mw_plugin_data *pd = PLUGIN_DATA(gc);
+  struct mwAwareIdBlock i = { mwAware_USER, b->name, NULL };
+  const char *t;
 
-  struct mw_plugin_data *pd = PLUGIN_DATA(b->account->gc);
-  struct mwIdBlock i = { b->name, NULL };
-  const char *t = mwServiceAware_getText(pd->srvc_aware, &i);
-  return t? g_strdup(t): NULL;
+  t = mwServiceAware_getText(pd->srvc_aware, &i);
+  return t ? g_strdup(t) : NULL;
 }
 
 
@@ -736,7 +877,7 @@
   GaimConnection *gc = b->account->gc;
   struct mw_plugin_data *pd = PLUGIN_DATA(gc);
 
-  struct mwIdBlock t = { b->name, NULL };
+  struct mwAwareIdBlock t = { mwAware_USER, b->name, NULL };
 
   char *stat, *ret;
   stat = mw_status_text(b);
@@ -773,9 +914,10 @@
 
   mwUserStatus_clone(&stat, &s->status);
 
-  /* re-reading the specification, this is incorrect. It should be the count
-     of minutes since last action. In order to fix this, I am going to turn
-     off all idle-time reporting for the next meanwhile version. */
+  /* re-reading the specification, this is incorrect. It should be the
+     count of minutes since last action. In order to fix this, I am
+     going to turn off all idle-time reporting for the next meanwhile
+     version. */
 
   /* stat.time = (t > 0)? time(NULL) - t: 0; */
 
@@ -815,12 +957,12 @@
   mwUserStatus_clone(&stat, &s->status);
 
   if(state != NULL) {
-    /* when we go to/from a standard state, the state indicates whether we're
-       away or not */
+    /* when we go to/from a standard state, the state indicates
+       whether we're away or not */
 
     if(! strcmp(state, GAIM_AWAY_CUSTOM)) {
-      /* but when we go to/from a custom state, then it's the message which
-	 indicates whether we're away or not */
+      /* but when we go to/from a custom state, then it's the message
+	 which indicates whether we're away or not */
 
       if(message != NULL) {
 	stat.status = mwStatus_AWAY;
@@ -877,61 +1019,47 @@
 }
 
 
-static void mw_add_buddy(GaimConnection *gc, const char *name,
-			 GaimGroup *group) {
+static struct mwAwareList *ensure_list(GaimConnection *gc, GaimGroup *group) {
 
   struct mw_plugin_data *pd = PLUGIN_DATA(gc);
+  struct mwAwareList *list;
 
-  /* later support name@community splits */
-  struct mwIdBlock t = { (char *) name, NULL };
+  list = (struct mwAwareList *) g_hash_table_lookup(pd->list_map, group);
+  if(! list) {
 
-  mwServiceAware_add(pd->srvc_aware, &t, 1);
+    g_message("creating aware list for group %s", group->name);
+    list = mwAwareList_new(pd->srvc_aware);
+    mwAwareList_setOnAware(list, got_aware, gc);
+    g_hash_table_replace(pd->list_map, group, list);
+  }
+  
+  return list;
 }
 
 
-static void mw_add_buddies(GaimConnection *gc, GList *buddies) {
-  struct mw_plugin_data *pd = PLUGIN_DATA(gc);
-  unsigned int count, c;
-  struct mwIdBlock *t;
+static void mw_add_buddy(GaimConnection *gc,
+			 GaimBuddy *buddy, GaimGroup *group) {
 
-  count = g_list_length(buddies);
-  t = g_new0(struct mwIdBlock, count);
+  struct mwAwareIdBlock t = { mwAware_USER, (char *) buddy->name, NULL };
+  struct mwAwareList *list;
 
-  for(c = count; c--; buddies = buddies->next)
-    (t + c)->user = (char *) buddies->data;
-  
-  mwServiceAware_add(pd->srvc_aware, t, count);
-  g_free(t);
+  GaimGroup *found = gaim_find_buddys_group(buddy);
+  list = ensure_list(gc, found);
+
+  mwAwareList_addAware(list, &t, 1);
 }
 
 
 static void mw_remove_buddy(GaimConnection *gc,
-			    const char *name, const char *group) {
+			    GaimBuddy *buddy, GaimGroup *group) {
   
-  struct mw_plugin_data *pd = PLUGIN_DATA(gc);
-
-  /* later support name@community splits */
-  struct mwIdBlock t = { (char *) name, NULL };
-
-  mwServiceAware_remove(pd->srvc_aware, &t, 1);
-}
-
+  struct mwAwareIdBlock t = { mwAware_USER, (char *) buddy->name, NULL };
+  struct mwAwareList *list = ensure_list(gc, group);
 
-static void mw_remove_buddies(GaimConnection *gc, GList *buddies,
-			      const char *group) {
+  GaimGroup *found = gaim_find_buddys_group(buddy);
+  list = ensure_list(gc, found);
 
-  struct mw_plugin_data *pd = PLUGIN_DATA(gc);
-  unsigned int count, c;
-  struct mwIdBlock *t;
-
-  count = g_list_length(buddies);
-  t = g_new0(struct mwIdBlock, count);
-
-  for(c = count; c--; buddies = buddies->next)
-    (t + c)->user = (char *) buddies->data;
-  
-  mwServiceAware_remove(pd->srvc_aware, t, count);
-  g_free(t);
+  mwAwareList_removeAware(list, &t, 1);
 }
 
 
@@ -958,13 +1086,13 @@
   char *name = g_hash_table_lookup(components, CHAT_NAME_KEY);
 
   if(name) {
-    DEBUG_INFO(" accepting conference invite\n");
+    DEBUG_INFO(" accepting conference invite");
     conf = mwConference_findByName(srvc, name);
     if(conf) mwConference_accept(conf);
 
   } else {
     char *topic;
-    DEBUG_INFO(" creating new conference\n");
+    DEBUG_INFO(" creating new conference");
 
     topic = (char *) g_hash_table_lookup(components, CHAT_TOPIC_KEY);
     conf = mwConference_new(srvc);
@@ -972,7 +1100,7 @@
     mwConference_create(conf);
   }
 
-  DEBUG_INFO(" ... leaving mw_chat_join\n");
+  DEBUG_INFO(" ... leaving mw_chat_join");
 }
 
 
@@ -1029,9 +1157,10 @@
 
 static GaimPluginProtocolInfo prpl_info = {
   GAIM_PRPL_API_VERSION, /* options */
-  0, /* flags? */
+  0, /* flags */
   NULL,
   NULL,
+  NO_BUDDY_ICONS, /* icon spec */
   mw_blist_icon,
   mw_blist_emblems,
   mw_list_status_text,
@@ -1049,9 +1178,9 @@
   mw_set_idle,
   NULL, /* change password, */
   mw_add_buddy,
-  mw_add_buddies,
+  NULL, /* mw_add_buddies, */
   mw_remove_buddy,
-  mw_remove_buddies,
+  NULL, /* mw_remove_buddies, */
   NULL, /* mw_add_permit, */
   NULL, /* mw_add_deny, */
   NULL, /* mw_rem_permit, */
@@ -1107,7 +1236,7 @@
   NULL,                           /**< ui_info        */
   &prpl_info,                     /**< extra_info     */
   NULL,                           /**< prefs info     */
-  NULL
+  NULL                            /**< actions        */
 };
 
 
@@ -1121,16 +1250,11 @@
   opt = gaim_account_option_int_new("Port", MW_KEY_PORT, PLUGIN_DEFAULT_PORT);
   prpl_info.protocol_options = g_list_append(prpl_info.protocol_options, opt);
 
-  /*
-  opt = gaim_account_option_string_new("Community", MW_KEY_COMMUNITY,
-				       PLUGIN_DEFAULT_COMMUNITY);
-  prpl_info.protocol_options = g_list_append(prpl_info.protocol_options, opt);
-  */
-
   meanwhile_plugin = plugin;
 }
 
 
-GAIM_INIT_PLUGIN(meanwhile, init_plugin, info)
+GAIM_INIT_PLUGIN(meanwhile, init_plugin, info);
 
 
+/* The End. */
