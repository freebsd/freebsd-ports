--- src/libm-tester/iutsimdmain.c.orig	2021-11-18 16:48:35 UTC
+++ src/libm-tester/iutsimdmain.c
@@ -9,16 +9,16 @@
 #include <signal.h>
 #include <setjmp.h>
 
-static jmp_buf sigjmp;
-
 int do_test(int argc, char **argv);
 int check_featureDP(double d);
 int check_featureSP(float d);
 
 #if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)
+static jmp_buf sigjmp;
 #define SETJMP(x) setjmp(x)
 #define LONGJMP longjmp
 #else
+static sigjmp_buf sigjmp;
 #define SETJMP(x) sigsetjmp(x, 1)
 #define LONGJMP siglongjmp
 #endif
