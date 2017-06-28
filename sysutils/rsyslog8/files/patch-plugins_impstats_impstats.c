--- plugins/impstats/impstats.c.orig	2017-04-28 07:04:53 UTC
+++ plugins/impstats/impstats.c
@@ -36,6 +36,7 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <unistd.h>
 
 #include "dirty.h"
 #include "cfsysline.h"
