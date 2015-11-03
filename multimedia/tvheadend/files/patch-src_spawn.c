--- src/spawn.c.orig	2015-09-25 13:57:59 UTC
+++ src/spawn.c
@@ -28,6 +28,7 @@
 #include <syslog.h>
 #include <fcntl.h>
 #include <dirent.h>
+#include <signal.h>
 
 #include "tvheadend.h"
 #include "tvhpoll.h"
