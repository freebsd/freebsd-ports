--- include/blas++.h~	Tue Nov 19 13:30:26 2002
+++ include/blas++.h	Tue Nov 19 13:32:03 2002
@@ -11,7 +11,11 @@
 #include "blas2++.h"
 #include "blas3++.h"
 
-double abs(double);
+inline double abs(double a)
+{
+  if(a>=0) return a;
+  return -a;
+}
 
 //-------------------------------------
 // Vector/Vector operators
