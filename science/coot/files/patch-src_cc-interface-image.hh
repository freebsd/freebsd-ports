--- src/cc-interface-image.hh.orig	2018-06-08 16:50:29 UTC
+++ src/cc-interface-image.hh
@@ -1,5 +1,6 @@
 
 #ifdef USE_PYTHON
+#include <Python.h>
 
 // make a png given the info in text_info_dict
 // fields: text, font, size, colour, slant, weight
