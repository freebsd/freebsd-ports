--- ../../src/portab.h.orig	Sat Apr  6 15:40:58 2002
+++ ../../src/portab.h	Sat Apr  6 15:41:21 2002
@@ -52,6 +52,7 @@
 
 #elif defined(LINUX) || defined(DJGPP)
 
+#include "../../../config.h"
 
 #ifdef _DEBUG
 
@@ -72,7 +73,11 @@
 
 #if defined(LINUX)
 
+#if defined(HAVE_STDINT_H)
 #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
 
 #else
 
