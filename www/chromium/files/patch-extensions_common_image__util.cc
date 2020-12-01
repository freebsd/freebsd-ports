--- extensions/common/image_util.cc.orig	2020-11-13 06:36:43 UTC
+++ extensions/common/image_util.cc
@@ -20,7 +20,11 @@
 #include "base/strings/stringprintf.h"
 #include "base/time/time.h"
 #include "base/timer/elapsed_timer.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkCanvas.h"
 #include "third_party/skia/include/core/SkColor.h"
