--- ./classes/include/ArtsAsMatrixData.hh.orig	Mon Oct  2 13:05:14 2000
+++ ./classes/include/ArtsAsMatrixData.hh	Wed Sep 25 16:38:10 2002
@@ -52,11 +52,10 @@
 
 #ifdef HAVE_IOSTREAM
   #include <iostream>
+  using namespace std;
 #else
   #include <iostream.h>
 #endif
-// #include <istream.h>
-// #include <ostream.h>
 #include <algorithm>
 
 #include "ArtsAsMatrixEntry.hh"
