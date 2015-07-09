--- src/zlog/src/rule.c.orig	2015-07-10 03:32:15.578671000 +0900
+++ src/zlog/src/rule.c	2015-07-10 03:35:22.106690000 +0900
@@ -8,12 +8,12 @@
 
 #include "fmacros.h"
 
+#include <sys/types.h>
 #include <string.h>
 #include <ctype.h>
 #include <syslog.h>
 #include <errno.h>
 #include <stdlib.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
