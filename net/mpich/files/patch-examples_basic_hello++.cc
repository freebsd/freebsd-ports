--- examples/basic/hello++.cc.orig	Wed Jul 12 22:23:29 2000
+++ examples/basic/hello++.cc	Fri Jul 27 23:01:44 2007
@@ -26,7 +26,9 @@
 // OR OTHER RIGHTS.
 //
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
+
 #include "mpi.h"
 
 int
