--- tools/rsyslogd.c.orig	2014-12-10 15:46:03 UTC
+++ tools/rsyslogd.c
@@ -32,6 +32,7 @@
 #else
 #	include <sys/errno.h>
 #endif
+#include <unistd.h>
 #include "sd-daemon.h"
 
 #include "wti.h"
