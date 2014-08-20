--- ./runtime/lookup.c.orig	2014-08-20 11:50:14.000000000 -0400
+++ ./runtime/lookup.c	2014-08-20 11:52:52.000000000 -0400
@@ -26,8 +26,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <json/json.h>
-#include <json/json.h>
+#include <json-c/json.h>
+#include <json-c/json.h>
 #include <assert.h>
 
 #include "rsyslog.h"
