--- ./classes/src/ArtsNetMatrixAggregatorMap.cc.orig	Mon Oct  2 13:05:25 2000
+++ ./classes/src/ArtsNetMatrixAggregatorMap.cc	Wed Sep 25 16:38:10 2002
@@ -46,9 +46,11 @@
 
 #include <string>
 #ifdef HAVE_FSTREAM
-  #include <fstream>
+#  include <fstream>
+#  include <iterator>
+   using namespace std;
 #else
-  #include <fstream.h>
+#  include <fstream.h>
 #endif
 
 #include "ArtsNetMatrixAggregatorMap.hh"
