--- deps/v8/src/log-utils.h.orig	2016-06-02 21:53:46 UTC
+++ deps/v8/src/log-utils.h
@@ -9,6 +9,9 @@
 
 #include <cstdarg>
 
+#include <cstdio>
+#include <cstdarg>
+
 #include "src/allocation.h"
 #include "src/base/platform/mutex.h"
 #include "src/flags.h"
