Index: server/gkrellmd.h
diff -u server/gkrellmd.h.orig server/gkrellmd.h
--- server/gkrellmd.h.orig	Mon Apr 12 23:32:29 2004
+++ server/gkrellmd.h	Tue Apr 13 17:16:02 2004
@@ -105,8 +105,12 @@
 #endif
 
 #if !defined(WIN32)
+#if !defined(GKRELLMD_SYS_ETC)
 #define	GKRELLMD_SYS_ETC	"/etc"
+#endif
+#if 0
 #define GKRELLMD_LOCAL_ETC	"/usr/local/etc"
+#endif
 #endif
 
 
