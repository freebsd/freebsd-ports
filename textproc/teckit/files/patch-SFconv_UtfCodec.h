--- SFconv/UtfCodec.h.orig	2017-06-23 19:39:26 UTC
+++ SFconv/UtfCodec.h
@@ -28,11 +28,7 @@ of the License or (at your option) any l
 
 #include <cstddef>
 #include <cstdlib>
-#include <cstdint>
-
-using std::int8_t;
-using std::uint8_t;
-using std::ptrdiff_t;
+#include <stdint.h>
 
 typedef uint32_t  uchar_t;
 
