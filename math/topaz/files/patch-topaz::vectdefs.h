--- topaz/vectdefs.h.orig	Wed Dec  4 23:02:28 2002
+++ topaz/vectdefs.h	Fri Dec 27 04:37:32 2002
@@ -28,6 +28,8 @@
 #include "vect.h"
 #include "pointdefs.h"
 
+using namespace std;
+
 typedef rvect<int> intarray;
 typedef rvect<double> doublearray;
 typedef vect<string> stringarray;
