--- src/defs.h.orig	2015-01-03 11:21:50.000000000 -0500
+++ src/defs.h	2015-01-03 11:50:57.000000000 -0500
@@ -154,17 +154,21 @@
 
 /* Prototypes for these routines are missing from some systems. */
 #if !HAVE_DECL_ETHER_NTOA
-extern char *ether_ntoa (const struct ether_addr *e);
+extern char *ether_ntoa (const struct libnet_ether_addr *e);
 #endif
 #if !HAVE_DECL_ETHER_ATON
-extern struct ether_addr *ether_aton(const char *hostname);
+extern struct libnet_ether_addr *ether_aton(const char *hostname);
 #endif
 #if !HAVE_DECL_ETHER_NTOHOST
-extern int ether_ntohost (char *hostname, const struct ether_addr *e);
+extern int ether_ntohost (char *hostname, const struct libnet_ether_addr *e);
 #endif
 #if !HAVE_DECL_ETHER_HOSTTON
-extern int ether_hostton (const char *hostname, struct ether_addr *e);
+extern int ether_hostton (const char *hostname, struct libnet_ether_addr *e);
 #endif
 
+/* libnet 1.1.3+ has ether_addr_octet in struct libnet_ether_addr{} */
+#ifndef STRUCT_ETHER_ADDR_HAS_ETHER_ADDR_OCTET
+#define STRUCT_ETHER_ADDR_HAS_ETHER_ADDR_OCTET 1
+#endif
 
 #endif /* not DEFS_H */
