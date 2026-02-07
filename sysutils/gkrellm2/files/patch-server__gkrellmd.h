--- server/gkrellmd.h.orig	2010-09-14 16:34:34 UTC
+++ server/gkrellmd.h
@@ -131,8 +131,12 @@
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
 
 
