--- deps/stringprep/c_src/stringprep.cpp.orig	2016-03-04 14:58:46 UTC
+++ deps/stringprep/c_src/stringprep.cpp
@@ -19,6 +19,7 @@
  */
 
 #include <string.h>
+#include <libutil.h>
 #include <erl_nif.h>
 
 #include "uni_data.c"
