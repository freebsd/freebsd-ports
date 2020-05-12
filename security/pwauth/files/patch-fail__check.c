--- fail_check.c.orig	2020-04-11 16:28:08 UTC
+++ fail_check.c
@@ -35,7 +35,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <utmp.h>
+#include <utmpx.h>
 
 #include "config.h"
 #include "fail_log.h"
