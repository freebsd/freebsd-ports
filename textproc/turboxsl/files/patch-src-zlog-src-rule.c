--- src/zlog/src/rule.c.orig	2015-07-02 18:01:10 UTC
+++ src/zlog/src/rule.c
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
