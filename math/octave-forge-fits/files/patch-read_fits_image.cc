--- read_fits_image.cc-orig	2011-07-13 19:46:54.000000000 +0000
+++ read_fits_image.cc	2011-07-13 19:47:19.000000000 +0000
@@ -9,6 +9,7 @@
 #include <iostream>
 #include <sstream>
 #include <octave/oct.h>
+#include <octave/MArrayN.h>
 
 extern "C"
 {
