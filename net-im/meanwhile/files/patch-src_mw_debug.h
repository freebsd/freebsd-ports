--- src/mw_debug.h.orig	Sun Mar 13 19:52:16 2005
+++ src/mw_debug.h	Sun Mar 13 19:52:51 2005
@@ -9,8 +9,12 @@
 #define NSTR(str) ((str != NULL)? str: "(null)")
 
 
+#ifndef g_debug
 #define g_debug(format...) g_log(G_LOG_DOMAIN, G_LOG_LEVEL_DEBUG, format)
+#endif
+#ifndef g_info
 #define g_info(format...) g_log(G_LOG_DOMAIN, G_LOG_LEVEL_INFO, format)
+#endif
 
 
 /**
