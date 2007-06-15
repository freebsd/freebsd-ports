--- classes/include/CflowdPortMatrix.hh.orig	Fri Jun 15 16:36:13 2007
+++ classes/include/CflowdPortMatrix.hh	Fri Jun 15 16:47:35 2007
@@ -51,6 +51,8 @@
 
 #include <map>
 #include <iostream.h>
+#include <strstream>
+using namespace std;
 
 #include "CflowdPortMatrixKey.hh"
 #include "CflowdPortMatrixTrafficCounter.hh"
