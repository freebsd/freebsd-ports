--- src/util/sys_defs.h.orig	2009-07-29 16:58:28.000000000 -0300
+++ src/util/sys_defs.h	2009-07-29 16:59:15.000000000 -0300
@@ -110,6 +110,10 @@
 #define HAS_DUPLEX_PIPE			/* 4.1 breaks with kqueue(2) */
 #endif
 
+#if (__FreeBSD_version >= 702104 && __FreeBSD_version < 800000) || (__FreeBSD_version >= 800099)
+#define HAS_CLOSEFROM
+#endif
+
 /* OpenBSD version is year+month */
 
 #if OpenBSD >= 199805			/* XXX */
