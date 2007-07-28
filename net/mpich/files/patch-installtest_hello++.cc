--- installtest/hello++.cc.orig	Fri May 26 23:28:29 2000
+++ installtest/hello++.cc	Fri Jul 27 23:02:01 2007
@@ -26,7 +26,9 @@
 // OR OTHER RIGHTS.
 //
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
+
 // modified to reference the master mpi.h file, to meet the MPI standard spec.
 #include "mpi.h"
 
