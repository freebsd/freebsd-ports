--- src/INTERP_KERNELTest/BasicMainTest.hxx.orig	2025-10-15 11:21:58 UTC
+++ src/INTERP_KERNELTest/BasicMainTest.hxx
@@ -32,7 +32,7 @@
 #include <iostream>
 #include <fstream>
 
-#if !defined WIN32 && !defined __APPLE__
+#if !defined WIN32 && !defined __APPLE__ && !defined __FreeBSD__
 #include <fpu_control.h>
 #endif
 
@@ -46,7 +46,7 @@ main(int argc, char *argv[])
 int
 main(int argc, char *argv[])
 {
-#if !defined WIN32 && !defined __APPLE__
+#if !defined WIN32 && !defined __APPLE__ && !defined __FreeBSD__
     fpu_control_t cw = _FPU_DEFAULT & ~(_FPU_MASK_IM | _FPU_MASK_ZM | _FPU_MASK_OM);
     _FPU_SETCW(cw);
 #endif
