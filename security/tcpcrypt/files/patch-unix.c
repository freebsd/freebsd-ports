--- src/unix.c.orig	2014-09-10 16:22:26.000000000 -0700
+++ src/unix.c	2014-10-31 23:59:29.000000000 -0700
@@ -57,7 +57,13 @@
         s_in.sin_addr   = ip->ip_dst;
         s_in.sin_port   = tcp->th_dport;
 
-#if defined(__FreeBSD__) || defined(__DARWIN_UNIX03)
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 1000022
+	#define HO_LEN
+#endif
+#endif
+#ifdef __DARWIN_UNIX03
 	#define HO_LEN
 #endif
 #ifdef HO_LEN
