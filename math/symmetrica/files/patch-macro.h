--- macro.h.orig	2007-12-06 16:30:56 UTC
+++ macro.h
@@ -1,5 +1,8 @@
 /* file: macro.h symmetrica source code */
+/* Patch from SageMath */
 #ifndef MACRO_H
+
+#include "string.h"
 
 #ifdef SYMMAGMA
 #define SYM_MALLOC(a) mem_malloc(a)
