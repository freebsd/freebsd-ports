--- src/bin/lttng-relayd/stream.c.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-relayd/stream.c
@@ -22,6 +22,7 @@
 #include <common/utils.h>
 #include <common/defaults.h>
 #include <urcu/rculist.h>
+#include <sys/types.h>
 #include <sys/stat.h>
 
 #include "lttng-relayd.h"
