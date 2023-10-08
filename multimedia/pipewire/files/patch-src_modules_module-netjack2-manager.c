--- src/modules/module-netjack2-manager.c.orig	2023-10-09 19:51:26 UTC
+++ src/modules/module-netjack2-manager.c
@@ -37,6 +37,10 @@
 
 #include "module-netjack2/peer.c"
 
+#ifdef __FreeBSD__
+#define ifr_ifindex ifr_index
+#endif
+
 #ifndef IPTOS_DSCP
 #define IPTOS_DSCP_MASK 0xfc
 #define IPTOS_DSCP(x) ((x) & IPTOS_DSCP_MASK)
