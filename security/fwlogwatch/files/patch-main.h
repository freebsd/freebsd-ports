--- main.h.orig	Sun Mar 23 02:41:37 2003
+++ main.h	Mon Mar 31 10:37:08 2003
@@ -9,9 +9,15 @@
 
 /* Paths */
 
+#ifndef INSTALL_DIR
 #define INSTALL_DIR "/usr/local"
+#endif
+#ifndef CONF_DIR
 #define CONF_DIR "/etc"
+#endif
+#ifndef LOCALE_DIR
 #define LOCALE_DIR "/usr"
+#endif
 
 /* i18n */
 
