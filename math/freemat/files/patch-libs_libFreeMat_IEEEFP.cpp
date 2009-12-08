--- libs/libFreeMat/IEEEFP.cpp.orig	2009-10-08 09:42:00.000000000 +0700
+++ libs/libFreeMat/IEEEFP.cpp	2009-10-08 09:43:46.000000000 +0700
@@ -17,6 +17,7 @@
  *
  */
 #include "IEEEFP.hpp"
+#include <stdio.h>
 
 static bool endianDetected = false;
 static bool bigEndian = false;
