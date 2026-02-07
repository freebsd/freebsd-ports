--- src/spamprobe/Command_import.cc.orig	2013-11-04 20:00:58.000000000 +0100
+++ src/spamprobe/Command_import.cc	2013-11-04 20:01:11.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include <fstream>
 #include "LineReader.h"
 #include "IstreamCharReader.h"
