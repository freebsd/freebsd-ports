--- src/polkit/polkit-config.c.orig	2007-12-23 00:25:46.000000000 -0500
+++ src/polkit/polkit-config.c	2007-12-23 00:25:51.000000000 -0500
@@ -39,7 +39,6 @@
 #include <grp.h>
 #include <unistd.h>
 #include <errno.h>
-#include <sys/inotify.h>
 #include <regex.h>
 #include <syslog.h>
 #include <regex.h>
