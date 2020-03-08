--- extensions/common/image_util.cc.orig	2020-03-03 18:53:08 UTC
+++ extensions/common/image_util.cc
@@ -18,7 +18,11 @@
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
