--- extensions/common/image_util.cc.orig	2016-03-05 21:28:20.783511398 +0100
+++ extensions/common/image_util.cc	2016-03-05 21:28:33.615510847 +0100
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
 #include "ui/gfx/color_utils.h"
 
