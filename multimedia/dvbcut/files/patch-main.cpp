--- src/main.cpp~	2007-04-13 19:36:26 +0200
+++ src/main.cpp	2007-07-17 01:10:36 +0200
@@ -27,7 +27,9 @@
 #endif // HAVE_LIB_AO
 
 #include <qapplication.h>
+extern "C" {
 #include <ffmpeg/avformat.h>
+}
 #include <qimage.h>
 #include <qsettings.h>
 #include "dvbcut.h"
