--- extensions/common/image_util.cc.orig	2017-04-19 19:06:34 UTC
+++ extensions/common/image_util.cc
@@ -11,7 +11,11 @@
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_util.h"
 #include "base/strings/stringprintf.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "third_party/skia/include/core/SkColor.h"
 #include "third_party/skia/include/utils/SkParse.h"
 #include "ui/gfx/color_utils.h"
