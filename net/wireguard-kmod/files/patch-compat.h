Fix typing mistake in FreeBSD version

Submitted by:	Michael Butler <imb@protected-networks.net>
--- compat.h.orig	2022-06-10 17:21:17 UTC
+++ compat.h
@@ -8,7 +8,7 @@
 
 #include <sys/param.h>
 
-#if __FreeBSD_version < 1400517
+#if __FreeBSD_version < 1400057
 #include <sys/sockbuf.h>
 #define sbcreatecontrol(a, b, c, d, e) sbcreatecontrol(a, b, c, d)
 #endif
