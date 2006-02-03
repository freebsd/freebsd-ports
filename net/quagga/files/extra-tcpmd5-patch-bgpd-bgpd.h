--- bgpd/bgpd.h.orig	Wed Jan 11 03:10:10 2006
+++ bgpd/bgpd.h	Mon Jan 30 08:52:06 2006
@@ -347,6 +347,9 @@
 #define PEER_FLAG_DYNAMIC_CAPABILITY        (1 << 5) /* dynamic capability */
 #define PEER_FLAG_DISABLE_CONNECTED_CHECK   (1 << 6) /* disable-connected-check */
 #define PEER_FLAG_LOCAL_AS_NO_PREPEND       (1 << 7) /* local-as no-prepend */
+#ifdef QUAGGA_TCP_MD5SIG
+#define PEER_FLAG_TCP_SIGNATURE             (1 << 9) /* use TCP-MD5 digest */
+#endif /* QUAGGA_TCP_MD5SIG */
 
   /* NSF mode (graceful restart) */
   u_char nsf[AFI_MAX][SAFI_MAX];
@@ -522,6 +525,13 @@
 #define PEER_RMAP_TYPE_NOSET          (1 << 5) /* not allow to set commands */
 #define PEER_RMAP_TYPE_IMPORT         (1 << 6) /* neighbor route-map import */
 #define PEER_RMAP_TYPE_EXPORT         (1 << 7) /* neighbor route-map export */
+
+#ifdef QUAGGA_TCP_MD5SIG
+ /* TCP-MD5 Password Support -- bms */
+#define PEER_PASSWORD_MINLEN		1
+#define PEER_PASSWORD_MAXLEN		80	/* width of password field */
+ char password[PEER_PASSWORD_MAXLEN];
+#endif /* QUAGGA_TCP_MD5SIG */
 };
 
 /* This structure's member directly points incoming packet data
@@ -904,6 +914,11 @@
 
 extern int peer_local_as_set (struct peer *, as_t, int);
 extern int peer_local_as_unset (struct peer *);
+
+#ifdef QUAGGA_TCP_MD5SIG
+extern int peer_password_set (struct peer *, char *);
+extern int peer_password_unset (struct peer *);
+#endif /* QUAGGA_TCP_MD5SIG */
 
 extern int peer_prefix_list_set (struct peer *, afi_t, safi_t, int, const char *);
 extern int peer_prefix_list_unset (struct peer *, afi_t, safi_t, int);
