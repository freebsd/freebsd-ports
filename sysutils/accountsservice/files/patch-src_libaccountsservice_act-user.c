--- src/libaccountsservice/act-user.c.orig	2018-04-04 13:59:42 UTC
+++ src/libaccountsservice/act-user.c
@@ -26,8 +26,6 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
-#include <crypt.h>
-
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <gio/gio.h>
