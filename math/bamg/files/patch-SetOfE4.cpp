--- SetOfE4.cpp.orig	Thu Apr 23 15:01:05 1998
+++ SetOfE4.cpp	Fri Dec 19 09:40:37 2003
@@ -1,7 +1,9 @@
-#include <iostream.h> 
+#include <iostream> 
 #include "meshtype.h"
 #include "SetOfE4.h"
 
+using std::cerr;
+using std::endl;
 
  SetOfEdges4::SetOfEdges4(Int4 mmx,Int4 nnx)
    {nx=nnx;
