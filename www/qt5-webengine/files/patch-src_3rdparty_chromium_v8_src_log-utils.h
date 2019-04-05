--- src/3rdparty/chromium/v8/src/log-utils.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/v8/src/log-utils.h
@@ -15,6 +15,8 @@
 #include "src/flags.h"
 #include "src/ostreams.h"
 
+#include <stdarg.h>
+
 namespace v8 {
 namespace internal {
 
