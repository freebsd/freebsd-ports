--- src/dftfuncs.cpp.orig	2022-04-05 18:34:51 UTC
+++ src/dftfuncs.cpp
@@ -434,7 +434,7 @@ double exact_exchange(int func_id) {
     }
 
 
-#if XC_MAJOR_VERSION >= 6
+#if XC_MAJOR_VERSION > 6
     switch(xc_hyb_type(&func)) {
     case(XC_HYB_HYBRID):
       f=xc_hyb_exx_coef(&func);
@@ -480,7 +480,7 @@ bool is_supported(int func_id) {
       throw std::runtime_error(oss.str());
     }
     // Get flag
-#if XC_MAJOR_VERSION >= 6
+#if XC_MAJOR_VERSION > 6
     switch(xc_hyb_type(&func)) {
     case(XC_HYB_SEMILOCAL):
     case(XC_HYB_HYBRID):
@@ -514,7 +514,7 @@ bool is_range_separated(int func_id, bool check) {
       oss << "Functional "<<func_id<<" not found!";
       throw std::runtime_error(oss.str());
     }
-#if XC_MAJOR_VERSION >= 6
+#if XC_MAJOR_VERSION > 6
     ans=(xc_hyb_type(&func) == XC_HYB_CAM);
 #else
     // Get flag
@@ -571,7 +571,7 @@ void range_separation(int func_id, double & omega, dou
       xc_func_set_ext_params(&func, pars.memptr());
     }
 
-#if XC_MAJOR_VERSION >= 6
+#if XC_MAJOR_VERSION > 6
     switch(xc_hyb_type(&func)) {
     case(XC_HYB_HYBRID):
     case(XC_HYB_CAM):
