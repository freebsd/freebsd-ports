--- src/wmnetload.c.orig	2003-02-23 09:07:17 UTC
+++ src/wmnetload.c
@@ -37,7 +37,7 @@
 #include <sys/ioctl.h>
 #include <sys/time.h>
 #include <unistd.h>
-#include <dockapp.h>
+#include <libdockapp/dockapp.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif
