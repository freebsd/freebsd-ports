--- src/polkit/polkit-config.c.orig	2008-04-21 19:47:19.000000000 -0400
+++ src/polkit/polkit-config.c	2008-04-21 19:47:27.000000000 -0400
@@ -39,7 +39,6 @@
 #include <grp.h>
 #include <unistd.h>
 #include <errno.h>
-#include <sys/inotify.h>
 #include <regex.h>
 #include <syslog.h>
 #include <regex.h>
