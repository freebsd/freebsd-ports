--- src/3rdparty/chromium/ui/gfx/codec/png_codec.cc.orig	2022-02-07 13:39:41 UTC
+++ src/3rdparty/chromium/ui/gfx/codec/png_codec.cc
@@ -10,7 +10,7 @@
 #include "base/memory/raw_ptr.h"
 #include "base/notreached.h"
 #include "base/strings/string_util.h"
-#include "third_party/libpng/png.h"
+#include <png.h>
 #include "third_party/skia/include/core/SkBitmap.h"
 #include "third_party/skia/include/core/SkColorPriv.h"
 #include "third_party/skia/include/core/SkUnPreMultiply.h"
