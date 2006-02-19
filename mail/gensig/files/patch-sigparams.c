--- sigparams.c.orig	Sun Feb 19 14:51:19 2006
+++ sigparams.c	Sun Feb 19 14:52:31 2006
@@ -8,12 +8,15 @@
 #ifdef HAVE_STDIO_H
 #include <stdio.h>
 #endif
+#include <stdlib.h>
 #ifdef HAVE_TIME_H
 #include <time.h>
 #endif
 #ifdef HAVE_SYSLOG_H
 #include <syslog.h>
 #endif
+
+#include <wchar.h>
 
 #include "sigparams.h"
 #include "util.h"
