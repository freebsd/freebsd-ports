--- main.h.orig	Wed Aug 21 04:53:51 2002
+++ main.h	Fri Oct 25 03:09:26 2002
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
