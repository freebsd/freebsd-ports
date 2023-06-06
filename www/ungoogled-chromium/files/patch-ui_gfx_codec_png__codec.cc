--- ui/gfx/codec/png_codec.cc.orig	2023-06-05 19:39:05 UTC
+++ ui/gfx/codec/png_codec.cc
@@ -11,7 +11,7 @@
 #include "base/memory/raw_ptr_exclusion.h"
 #include "base/notreached.h"
 #include "base/strings/string_util.h"
-#include "third_party/libpng/png.h"
+#include <png.h>
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkColorPriv.h"
 #include "third_party/skia/include/core/SkUnPreMultiply.h"
