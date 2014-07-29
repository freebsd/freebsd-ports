Index: server/gkrellmd.h
diff -u server/gkrellmd.h.orig server/gkrellmd.h
--- server/gkrellmd.h.orig	2008-10-04 06:52:48.000000000 +0900
+++ server/gkrellmd.h	2008-10-04 19:55:03.000000000 +0900
@@ -118,8 +118,12 @@
 	#if !defined(GKRELLMD_SYSTEM_PLUGINS_DIR)
 		#define GKRELLMD_SYSTEM_PLUGINS_DIR	"/usr/lib/gkrellm2/plugins-gkrellmd"
 	#endif
+	#if !defined(GKRELLMD_SYS_ETC)
 	#define GKRELLMD_SYS_ETC	"/etc"
+	#endif
+	#if 0
 	#define GKRELLMD_LOCAL_ETC	"/usr/local/etc"
+	#endif
 #endif // !defined(WIN32)
 
 
