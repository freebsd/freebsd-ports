--- src/ParaMEDMEMTest/MPIMainTest.hxx.orig	2025-10-15 11:21:58 UTC
+++ src/ParaMEDMEMTest/MPIMainTest.hxx
@@ -33,7 +33,7 @@
 
 #include <iostream>
 #include <fstream>
-#ifndef WIN32
+#if !defined WIN32 && !defined __APPLE__ && !defined __FreeBSD__
 #include <fpu_control.h>
 #endif
 
@@ -47,7 +47,7 @@ main(int argc, char *argv[])
 int
 main(int argc, char *argv[])
 {
-#ifndef WIN32
+##if !defined WIN32 && !defined __APPLE__ && !defined __FreeBSD__
     fpu_control_t cw = _FPU_DEFAULT & ~(_FPU_MASK_IM | _FPU_MASK_ZM | _FPU_MASK_OM);
     _FPU_SETCW(cw);
 #endif
