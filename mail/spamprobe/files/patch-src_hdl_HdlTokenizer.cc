--- src/hdl/HdlTokenizer.cc.orig	2013-11-04 19:31:52.000000000 +0100
+++ src/hdl/HdlTokenizer.cc	2013-11-04 19:32:22.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "AbstractCharReader.h"
 #include "HdlError.h"
 #include "HdlToken.h"
