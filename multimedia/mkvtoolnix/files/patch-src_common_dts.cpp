--- src/common/dts.cpp.orig	2015-07-18 11:39:41 UTC
+++ src/common/dts.cpp
@@ -23,6 +23,10 @@
 #include "common/endian.h"
 #include "common/math.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 // ---------------------------------------------------------------------------
 
 namespace mtx { namespace dts {
