--- src/bin/lttng-sessiond/utils.h.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-sessiond/utils.h
@@ -18,6 +18,9 @@
 #ifndef _LTT_UTILS_H
 #define _LTT_UTILS_H
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 struct lttng_ht;
 
 const char *get_home_dir(void);
