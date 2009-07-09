--- src/util/sys_defs.h.orig	2009-07-08 13:38:52.000000000 +0400
+++ src/util/sys_defs.h	2009-07-08 13:46:41.000000000 +0400
@@ -110,6 +110,15 @@
 #define HAS_DUPLEX_PIPE			/* 4.1 breaks with kqueue(2) */
 #endif
 
+#if __FreeBSD_version >= 800100		/*
+					 * Actually, slightly before,
+					 * but we can't say precisely
+					 * when -- FreeBSD wasn't bumped
+					 * for closefrom() addition
+					 */
+#define HAS_CLOSEFROM
+#endif
+
 /* OpenBSD version is year+month */
 
 #if OpenBSD >= 199805			/* XXX */
