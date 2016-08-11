--- main.h.orig	2016-02-19 06:57:49.938584000 -0800
+++ main.h	2016-04-21 19:31:22.393058000 -0700
@@ -10,9 +10,15 @@
 
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
 
@@ -377,7 +383,9 @@
 /* Data structures */
 
 #include <time.h>
+#define _KERNEL
 #include <netinet/in.h>
+#undef _KERNEL
 
 struct log_line {
   time_t time;
