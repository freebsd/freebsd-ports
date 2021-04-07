--- log.c.orig	2000-06-22 22:55:13 UTC
+++ log.c
@@ -37,6 +37,7 @@
 #include <unistd.h>
 #include <syslog.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <stdarg.h>
 #include <errno.h>
 #include <signal.h>
