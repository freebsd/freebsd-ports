--- sympow-1.018.1.p9/src/fpu.c-orig	2012-02-01 01:01:04.000000000 +0000
+++ sympow-1.018.1.p9/src/fpu.c	2012-02-01 01:01:18.000000000 +0000
@@ -1,8 +1,4 @@
 
 void fpu_53bits()
 {
-#ifdef x86
-#include <fpu_control.h>
-fpu_control_t fpu_control=0x027f; _FPU_SETCW(fpu_control);
-#endif
 }
