--- Mesh2.cpp.orig	Thu Dec 23 17:25:52 1999
+++ Mesh2.cpp	Thu Dec 18 22:30:08 2003
@@ -17,13 +17,13 @@
 #include <string.h>
 #include <math.h> 
 #include <time.h>
-#include <iostream.h>
+#include <iostream>
 
 #include "Mesh2.h"
 #include "QuadTree.h"
 #include "SetOfE4.h"
 
-
+using std::ostream;
 
 
 #ifdef DEBUG1
