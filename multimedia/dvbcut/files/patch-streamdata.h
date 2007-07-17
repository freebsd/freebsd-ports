--- src/streamdata.h~	2007-04-13 19:36:27 +0200
+++ src/streamdata.h	2007-07-17 01:12:01 +0200
@@ -21,7 +21,9 @@
 
 #include <string>
 #include <list>
+extern "C" {
 #include <ffmpeg/avformat.h>
+}
 
 #include "port.h"
 #include "tsfile.h"
