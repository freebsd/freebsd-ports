--- src/bin/lttng-sessiond/ust-consumer.c.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-sessiond/ust-consumer.c
@@ -21,6 +21,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <inttypes.h>
 
 #include <common/common.h>
