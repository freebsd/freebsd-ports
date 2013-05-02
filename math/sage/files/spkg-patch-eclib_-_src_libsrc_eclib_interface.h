--- eclib-20120830/src/libsrc/eclib/interface.h-orig	2013-04-26 23:46:24.000000000 +0000
+++ eclib-20120830/src/libsrc/eclib/interface.h	2013-04-26 23:47:09.000000000 +0000
@@ -48,6 +48,7 @@
 #include <iterator>
 using namespace std;
 #include "templates.h"
+#include <stdint.h>
 
 #ifndef MININT
 #define MININT numeric_limits<int>::min()
