diff -u gnuInterface.h.orig gnuInterface.h
--- gnuInterface.h.orig	Wed Sep 30 04:26:59 1998
+++ gnuInterface.h	Thu Oct 30 21:42:04 2003
@@ -35,15 +35,17 @@
 #define gnuInterface_included
 
 #include <string>
-#include <iostream.h>
-#include <fstream.h>
-#include <strstream.h>
+#include <iostream>
+#include <fstream>
+#include <sstream>
 #include <stdio.h>
 #include "gnuPlotFile.h"
 #include "gnuPlotFunction.h"
 #include "gnuMultiFile.h"
 #include "gnuMultiFunc.h"
 #include "gnuCurveFit.h"
+
+using namespace std;
 
 class gnuInterface
 {
