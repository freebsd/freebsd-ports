see https://github.com/jeromerobert/hmat-oss/issues/59

--- src/disable_threading.cpp.orig	2019-04-29 18:50:39 UTC
+++ src/disable_threading.cpp
@@ -37,6 +37,8 @@ extern "C" {
 // This function is private in openblas
 int  goto_get_num_procs(void);
 }
+
+void openblas_set_num_threads(int n);
 #endif
 
 namespace hmat {
