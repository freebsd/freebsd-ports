--- defines.h.orig	Tue Feb 26 17:40:49 2002
+++ defines.h	Fri Mar  8 18:51:27 2002
@@ -146,7 +146,7 @@
 including rpc/rpc.h breaks Solaris 6
 */
 #ifndef INADDR_LOOPBACK
-#define INADDR_LOOPBACK ((ulong)0x7f000001)
+#define INADDR_LOOPBACK ((u_long)0x7f000001)
 #endif
 
 /* Types */
