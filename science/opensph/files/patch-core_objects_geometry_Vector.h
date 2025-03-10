--- core/objects/geometry/Vector.h.orig	2024-10-15 17:00:09 UTC
+++ core/objects/geometry/Vector.h
@@ -9,9 +9,13 @@
 #include "objects/containers/Tuple.h"
 #include "objects/geometry/Generic.h"
 #include "objects/wrappers/Interval.h"
-#include <immintrin.h>
 #include <iomanip>
+#if defined(__arm__) || defined(__aarch64__)
+#include <sse2neon.h>
+#else
+#include <immintrin.h>
 #include <smmintrin.h>
+#endif
 
 NAMESPACE_SPH_BEGIN
 
