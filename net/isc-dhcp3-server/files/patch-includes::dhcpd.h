--- includes/dhcpd.h.orig	Mon Feb 10 02:22:46 2003
+++ includes/dhcpd.h	Wed Mar  3 16:20:09 2004
@@ -99,6 +99,9 @@
 	 (((x) >> OPTION_HASH_EXP) & \
 	  (OPTION_HASH_PTWO - 1))) % OPTION_HASH_SIZE;
 
+#define NOLINK 0
+#define HAVELINK 1
+
 enum dhcp_shutdown_state {
 	shutdown_listeners,
 	shutdown_omapi_connections,
@@ -783,6 +786,11 @@
 	unsigned remote_id_len;		/* Length of Remote ID. */
 
 	char name [IFNAMSIZ];		/* Its name... */
+	int ieee80211;                  /* True if media is ieee802.11 */
+	int havemedia;                  /* True if we have a media table */
+	int linkstate;                  /* True if we have link */
+	int polling;                    /* True if polling is enabled */
+	int forcediscover;              /* True if a discover is needed */
 	int index;			/* Its index. */
 	int rfdesc;			/* Its read file descriptor. */
 	int wfdesc;			/* Its write file descriptor, if
@@ -1845,6 +1853,9 @@
 extern const char *path_dhclient_pid;
 extern char *path_dhclient_script;
 extern int interfaces_requested;
+#ifdef ENABLE_POLLING_MODE
+extern int polling_interval;
+#endif
 
 extern struct client_config top_level_config;
 
@@ -1858,12 +1869,21 @@
 void send_decline PROTO ((void *));
 
 void state_reboot PROTO ((void *));
+#ifdef ENABLE_POLLING_MODE
+void state_background PROTO ((void *));
+void state_polling PROTO ((void *));
+#endif
 void state_init PROTO ((void *));
 void state_selecting PROTO ((void *));
 void state_requesting PROTO ((void *));
 void state_bound PROTO ((void *));
 void state_stop PROTO ((void *));
 void state_panic PROTO ((void *));
+
+#if __FreeBSD_version > 502010
+void set_ieee80211 PROTO ((struct interface_info *));
+#endif
+int interface_active PROTO ((struct interface_info *));
 
 void bind_lease PROTO ((struct client_state *));
 
