--- v8/src/log-utils.h.orig	2017-07-04 22:40:30.657540000 +0200
+++ v8/src/log-utils.h	2017-07-04 22:40:59.090730000 +0200
@@ -14,6 +14,8 @@
 #include "src/base/platform/mutex.h"
 #include "src/flags.h"
 
+#include <stdarg.h>
+
 namespace v8 {
 namespace internal {
 
