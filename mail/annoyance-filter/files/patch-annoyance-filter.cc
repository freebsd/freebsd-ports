--- annoyance-filter.cc.orig	Thu Sep 25 01:56:54 2003
+++ annoyance-filter.cc	Fri Jan  2 02:51:57 2004
@@ -114,7 +114,7 @@
 #define __GNU_LIBRARY__
 #undef __GETOPT_H__
 #endif
-#include "getopt.h"     
+#include <getopt.h>
 #include "statlib.h" 
 
 /*237:*/
