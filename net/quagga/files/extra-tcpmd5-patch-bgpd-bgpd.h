--- bgpd/bgpd.h.orig	Tue Oct 12 22:06:09 2004
+++ bgpd/bgpd.h	Fri Jan 28 21:03:40 2005
@@ -335,6 +335,9 @@
 #define PEER_FLAG_DYNAMIC_CAPABILITY        (1 << 6) /* dynamic capability */
 #define PEER_FLAG_ENFORCE_MULTIHOP          (1 << 7) /* enforce-multihop */
 #define PEER_FLAG_LOCAL_AS_NO_PREPEND       (1 << 8) /* local-as no-prepend */
+#ifdef QUAGGA_TCP_MD5SIG /* XXX should move to AF_INET/SFI_UNICAST below */
+#define PEER_FLAG_TCP_SIGNATURE             (1 << 9) /* use TCP-MD5 digest */
+#endif /* QUAGGA_TCP_MD5SIG */
 
   /* Per AF configuration flags. */
   u_int32_t af_flags[AFI_MAX][SAFI_MAX];
@@ -496,6 +499,13 @@
 #define PEER_RMAP_TYPE_NOSET          (1 << 5) /* not allow to set commands */
 #define PEER_RMAP_TYPE_IMPORT         (1 << 6) /* neighbor route-map import */
 #define PEER_RMAP_TYPE_EXPORT         (1 << 7) /* neighbor route-map export */
+
+#ifdef QUAGGA_TCP_MD5SIG
+  /* TCP-MD5 Password Support -- bms */
+#define PEER_PASSWORD_MINLEN		1
+#define PEER_PASSWORD_MAXLEN		80	/* width of password field */
+ char password[PEER_PASSWORD_MAXLEN];
+#endif /* QUAGGA_TCP_MD5SIG */
 };
 
 /* This structure's member directly points incoming packet data
@@ -879,6 +889,11 @@
 
 int peer_local_as_set (struct peer *, as_t, int);
 int peer_local_as_unset (struct peer *);
+
+#ifdef QUAGGA_TCP_MD5SIG
+int peer_password_set (struct peer *, char *);
+int peer_password_unset (struct peer *);
+#endif /* QUAGGA_TCP_MD5SIG */
 
 int peer_prefix_list_set (struct peer *, afi_t, safi_t, int, const char *);
 int peer_prefix_list_unset (struct peer *, afi_t, safi_t, int);
