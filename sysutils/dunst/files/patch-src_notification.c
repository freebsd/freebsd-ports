Implicitly declared basename() makes dunst dump core on FreeBSD 11.1

Upstream pull request: https://github.com/dunst-project/dunst/pull/354

--- src/notification.c.orig	2017-08-08 16:05:07 UTC
+++ src/notification.c
@@ -13,6 +13,7 @@
 #include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
+#include <libgen.h>
 
 #include "dbus.h"
 #include "dunst.h"
