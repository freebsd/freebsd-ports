diff -u logScaleOp.cpp.orig logScaleOp.cpp
--- logScaleOp.cpp.orig	Tue Jul 21 04:18:45 1998
+++ logScaleOp.cpp	Thu Oct 30 21:42:04 2003
@@ -26,7 +26,7 @@
 #include "logScaleOp.h"
 #include <string>
 #include <qstring.h>
-#include <strstream.h>
+#include <sstream>
 
 #define Inherited logScaleOpData
 
@@ -65,7 +65,7 @@
   x2Axis = gnuInt->getLogScaleX2Axis();
   y2Axis = gnuInt->getLogScaleY2Axis();
 
-  ostrstream temp;
+  ostringstream temp;
 
   temp << base << ends; // make sure to add terminator with ends, to avoid garbage
                         // from unterminated string
