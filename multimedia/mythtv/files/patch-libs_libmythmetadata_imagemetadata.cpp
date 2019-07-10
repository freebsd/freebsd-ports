--- libs/libmythmetadata/imagemetadata.cpp.orig	2019-07-07 08:48:08 UTC
+++ libs/libmythmetadata/imagemetadata.cpp
@@ -7,14 +7,7 @@
 #include "exitcodes.h"        // for ffprobe
 
 // libexiv2 for Exif metadata
-//#include <exiv2/exiv2.hpp>
-// Note: Older versions of Exiv2 don't have the exiv2.hpp include
-// file.  Using image.hpp instead seems to work.
-#ifdef _MSC_VER
-#include <exiv2/src/image.hpp>
-#else
-#include <exiv2/image.hpp>
-#endif
+#include <exiv2/exiv2.hpp>
 
 // To read FFMPEG Metadata
 extern "C" {
