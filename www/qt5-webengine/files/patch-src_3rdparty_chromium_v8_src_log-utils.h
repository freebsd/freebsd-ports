--- src/3rdparty/chromium/v8/src/log-utils.h.orig	2017-12-15 19:24:49.335089000 -0500
+++ src/3rdparty/chromium/v8/src/log-utils.h	2017-12-15 19:25:08.702391000 -0500
@@ -14,6 +14,8 @@
 #include "src/base/platform/mutex.h"
 #include "src/flags.h"
 
+#include <stdarg.h>
+
 namespace v8 {
 namespace internal {
 
