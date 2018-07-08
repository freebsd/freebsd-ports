--- src/cc-interface-image.hh.orig	2018-07-08 02:10:49 UTC
+++ src/cc-interface-image.hh
@@ -1,4 +1,5 @@
 
+#include <Python.h>
 
 // make a png given the info in text_info_dict
 // fields: text, font, size, colour, slant, weight
