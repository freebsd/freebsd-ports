--- inc/roxml-types.h.orig	2011-07-11 10:28:59.000000000 +0800
+++ inc/roxml-types.h	2011-07-11 10:29:10.000000000 +0800
@@ -27,6 +27,8 @@
 #include "roxml_win32_native.h"
 #endif
 
+#include <pthread.h>
+
 /** \typedef roxml_parse_func 
  *
  * \brief parser callback functions
