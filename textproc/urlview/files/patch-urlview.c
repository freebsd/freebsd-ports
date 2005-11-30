--- urlview.c.orig	Wed Nov  9 15:34:39 2005
+++ urlview.c	Wed Nov  9 15:35:06 2005
@@ -46,6 +46,8 @@
 #include <rx/rxposix.h>
 #endif
 
+#include "quote.h"
+
 #define DEFAULT_REGEXP "(((https?|ftp|gopher)://|(mailto|file|news):)[^' \t<>\"]+|(www|web|w3)\\.[-a-z0-9.]+)[^' \t.,;<>\"\\):]"
 #define DEFAULT_COMMAND "url_handler.sh %s"
 #define SYSTEM_INITFILE "/usr/local/etc/urlview.conf"
