--- include/flexfloat.h.orig	2020-05-04 23:21:19 UTC
+++ include/flexfloat.h
@@ -40,9 +40,10 @@ extern "C" {
 #pragma STDC FENV_ACCESS ON
 #endif
 
-#ifndef __STDC_IEC_559__
-#error "Implementation not IEEE compliant"
-#endif
+// not clear why this should/shouldn't
+//#ifndef __STDC_IEC_559__
+//#error "Implementation not IEEE compliant"
+//#endif
 
 // GCC versions before 8.2 (for sure not on 7.2, don't know when it was fixed) don't raise flags on comparisons correctly
 #if !defined(__GNUC__) || (defined(__GNUC__) && (__GNUC__ >= 8) && (__GNUC_MINOR__ >= 2))
