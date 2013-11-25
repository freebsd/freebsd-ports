--- urlview.c.orig	2013-07-19 22:44:59.000000000 +0100
+++ urlview.c	2013-07-19 22:45:22.000000000 +0100
@@ -46,6 +46,8 @@
 #include <rx/rxposix.h>
 #endif
 
+#include "quote.h"
+
 #define DEFAULT_REGEXP "(((https?|ftp|gopher)://|(mailto|file|news):)[^' \t<>\"]+|(www|web|w3)\\.[-a-z0-9.]+)[^' \t.,;<>\"\\):]"
 #define DEFAULT_COMMAND "firefox %s"
 #define SYSTEM_INITFILE "/usr/local/etc/urlview.conf"
@@ -61,7 +63,7 @@
   MOTION
 };
 
-extern int mutt_enter_string (unsigned char *buf, size_t buflen, int y, int x,
+extern int mutt_enter_string (char *buf, size_t buflen, int y, int x,
 		int flags);
 
 void search_forward (char *search, int urlcount, char **url, int *redraw, int *current, int *top)
