--- ext/core/src/util/timecodefunctions.cpp.orig	2023-03-25 20:23:08 UTC
+++ ext/core/src/util/timecodefunctions.cpp
@@ -20,6 +20,8 @@
 
 #include "util/timecodefunctions.h"
 
+#include <cmath>
+
 extern "C" {
 #include <libavutil/mathematics.h>
 }
