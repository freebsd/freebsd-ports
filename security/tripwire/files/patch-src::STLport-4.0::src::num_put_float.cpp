--- src/STLport-4.0/src/num_put_float.cpp.orig  Sat Feb 24 19:44:14 2001
+++ src/STLport-4.0/src/num_put_float.cpp       Sat Oct 12 02:55:14 2002
@@ -43,7 +43,7 @@
 
 # ifdef __STL_UNIX
 
-# ifdef __OpenBSD__
+# if defined(__OpenBSD__) || defined(__FreeBSD__)
 #  include <math.h>
 #  include <float.h>
 # else
