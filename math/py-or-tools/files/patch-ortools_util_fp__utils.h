--- ortools/util/fp_utils.h.orig	2020-07-20 23:21:30 UTC
+++ ortools/util/fp_utils.h
@@ -83,6 +83,8 @@ class ScopedFloatingPointEnv {
     excepts &= FE_ALL_EXCEPT;
 #ifdef __APPLE__
     fenv_.__control &= ~excepts;
+#elif defined(__FreeBSD__)
+    //fesetexceptflag(&fenv_, excepts);
 #else  // Linux
     fenv_.__control_word &= ~excepts;
 #endif
