--- plugins/impstats/impstats.c.orig	2014-12-10 15:46:20 UTC
+++ plugins/impstats/impstats.c
@@ -35,6 +35,7 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <unistd.h>
 
 #include "dirty.h"
 #include "cfsysline.h"
