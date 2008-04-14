--- src/throttled.h.orig	2008-04-14 13:38:37.000000000 +0200
+++ src/throttled.h	2008-04-14 13:38:47.000000000 +0200
@@ -39,6 +39,7 @@
 #include <sys/resource.h>
 #include <err.h>
 #include <errno.h>
+#include <signal.h>
 #include <sysexits.h>
 #include <syslog.h>
 #include <stdarg.h>
