Index: server/gkrellmd.h
diff -u server/gkrellmd.h.orig server/gkrellmd.h
--- server/gkrellmd.h.orig	Tue Aug 13 01:58:55 2002
+++ server/gkrellmd.h	Thu Aug 29 18:47:14 2002
@@ -107,7 +107,9 @@
 #define GKRELLMD_CONFIG     "gkrellmd.conf"
 
 #if !defined(WIN32)
+#if !defined(GKRELLMD_SYS_ETC)
 #define	GKRELLMD_SYS_ETC	"/etc"
+#endif
 #define GKRELLMD_LOCAL_ETC	"/usr/local/etc"
 #endif
 
