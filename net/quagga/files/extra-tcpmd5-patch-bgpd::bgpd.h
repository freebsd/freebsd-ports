--- bgpd/bgpd.h.orig	Wed Aug 27 05:09:16 2003
+++ bgpd/bgpd.h	Wed Jan  7 14:28:38 2004
@@ -312,6 +312,9 @@
 #define PEER_FLAG_DYNAMIC_CAPABILITY        (1 << 6) /* dynamic capability */
 #define PEER_FLAG_ENFORCE_MULTIHOP          (1 << 7) /* enforce-multihop */
 #define PEER_FLAG_LOCAL_AS_NO_PREPEND       (1 << 8) /* local-as no-prepend */
+#ifdef TCP_MD5SIG /* XXX should move to AF_INET/SFI_UNICAST below */
+#define PEER_FLAG_TCP_SIGNATURE             (1 << 9) /* use TCP-MD5 digest */
+#endif /* TCP_MD5SIG */
 
   /* Per AF configuration flags. */
   u_int32_t af_flags[AFI_MAX][SAFI_MAX];
@@ -441,6 +444,13 @@
 #define PEER_RMAP_TYPE_REDISTRIBUTE   (1 << 3) /* redistribute route-map */
 #define PEER_RMAP_TYPE_DEFAULT        (1 << 4) /* default-originate route-map */
 #define PEER_RMAP_TYPE_NOSET          (1 << 5) /* not allow to set commands */
+
+#ifdef TCP_MD5SIG
+  /* TCP-MD5 Password Support -- bms */
+#define PEER_PASSWORD_MINLEN		1
+#define PEER_PASSWORD_MAXLEN		80	/* width of password field */
+ char password[PEER_PASSWORD_MAXLEN];
+#endif /* TCP_MD5SIG */
 };
 
 /* This structure's member directly points incoming packet data
@@ -815,6 +825,11 @@
 
 int peer_local_as_set (struct peer *, as_t, int);
 int peer_local_as_unset (struct peer *);
+
+#ifdef TCP_MD5SIG
+int peer_password_set (struct peer *, char *);
+int peer_password_unset (struct peer *);
+#endif /* TCP_MD5SIG */
 
 int peer_prefix_list_set (struct peer *, afi_t, safi_t, int, char *);
 int peer_prefix_list_unset (struct peer *, afi_t, safi_t, int);
