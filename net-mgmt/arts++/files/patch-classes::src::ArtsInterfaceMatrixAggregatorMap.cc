--- ./classes/src/ArtsInterfaceMatrixAggregatorMap.cc.orig	Mon Oct  2 13:05:24 2000
+++ ./classes/src/ArtsInterfaceMatrixAggregatorMap.cc	Wed Sep 25 16:38:10 2002
@@ -46,7 +46,9 @@
 
 #include <string>
 #ifdef HAVE_FSTREAM
-  #include <fstream>
+# include <fstream>
+# include <iterator>
+  using namespace std;
 #else
   #include <fstream.h>
 #endif
