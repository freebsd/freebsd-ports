--- src/common/dts.cpp.orig	2015-06-08 14:19:36 UTC
+++ src/common/dts.cpp
@@ -19,6 +19,10 @@
 #include "common/endian.h"
 #include "common/math.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 // ---------------------------------------------------------------------------
 
 namespace mtx { namespace dts {
