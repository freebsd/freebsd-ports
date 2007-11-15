--- src/main.cpp~	2007-04-13 19:36:26 +0200
+++ src/main.cpp	2007-11-15 09:19:25 +0100
@@ -27,7 +27,9 @@
 #endif // HAVE_LIB_AO
 
 #include <qapplication.h>
+extern "C" {
 #include <ffmpeg/avformat.h>
+}
 #include <qimage.h>
 #include <qsettings.h>
 #include "dvbcut.h"
@@ -76,6 +78,7 @@
       else
         idxfilename=mpgfilename+".idx";
 
+    av_register_all();
     std::string errormessage;
     mpgfile *mpg=mpgfile::open(mpgfilename,&errormessage);
 
