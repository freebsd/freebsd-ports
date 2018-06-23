--- libs/libMatC/CArray.cpp.orig	2018-06-22 09:05:35 UTC
+++ libs/libMatC/CArray.cpp
@@ -534,7 +534,7 @@ void* carray_get_aa(void* interp, void* arg, void* rnd
 extern "C" EXPORT
 double carray_get_ss(void* interp, void* arg, double row, double col, bool *flag)
 {
-  if (*flag) return NULL;
+  if (*flag) return 0.0L;
   try
     {
       CArray *cp = cast(arg);
@@ -569,7 +569,7 @@ double carray_get_ss(void* interp, void* arg, double r
 extern "C" EXPORT
 double carray_get_s(void* interp, void* arg, double row, bool *flag)
 {
-  if (*flag) return NULL;
+  if (*flag) return 0.0L;
   try
     {
       CArray *cp = cast(arg);
