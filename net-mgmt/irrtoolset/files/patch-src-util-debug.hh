--- src/util/debug.hh.orig	2002-04-09 13:48:49.000000000 +0200
+++ src/util/debug.hh
@@ -75,7 +75,11 @@
 
 #include "config.h"
 #ifdef DEBUG
+#if (__GNUC__ > 2)
+#include <iostream>
+#else
 #include <iostream.h>
+#endif
 
 #define DBG_ERR             1
 #define DBG_INFO            2 
