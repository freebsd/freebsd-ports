--- Source/common.h.orig	Wed Aug 10 17:29:30 2005
+++ Source/common.h	Sun May 27 09:51:29 2007
@@ -31,4 +31,7 @@
 #include "alloc.h"
 #include "util.h"
 
+#ifndef __STDC_CONSTANT_MACROS
+#define __STDC_CONSTANT_MACROS 1
+#endif
 
