--- extensions/common/image_util.cc.orig	2018-12-03 21:16:58.000000000 +0100
+++ extensions/common/image_util.cc	2018-12-13 23:08:46.488425000 +0100
@@ -13,7 +13,11 @@
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_util.h"
 #include "base/strings/stringprintf.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkColor.h"
 #include "third_party/skia/include/utils/SkParse.h"
