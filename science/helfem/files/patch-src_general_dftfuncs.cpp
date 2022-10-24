--- src/general/dftfuncs.cpp.orig	2021-09-12 09:32:14 UTC
+++ src/general/dftfuncs.cpp
@@ -388,7 +388,7 @@ double exact_exchange(int func_id) {
       throw std::runtime_error(oss.str());
     }
 
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION < 7
     switch(func.info->family)
       {
 #ifdef XC_FAMILY_HYB_LDA
@@ -431,7 +431,7 @@ bool is_supported(int func_id) {
       throw std::runtime_error(oss.str());
     }
     // Get flag
-#if XC_MAJOR_VERSION >= 6
+#if XC_MAJOR_VERSION > 6
     switch(xc_hyb_type(&func)) {
     case(XC_HYB_SEMILOCAL):
     case(XC_HYB_HYBRID):
@@ -463,7 +463,7 @@ void is_range_separated(int func_id, bool & erf, bool 
       throw std::runtime_error(oss.str());
     }
     // Get flag
-#if XC_MAJOR_VERSION < 6
+#if XC_MAJOR_VERSION < 7
     erf=(func.info->flags & XC_FLAGS_HYB_CAM) || (func.info->flags & XC_FLAGS_HYB_LC);
     yukawa=(func.info->flags & XC_FLAGS_HYB_CAMY) || (func.info->flags & XC_FLAGS_HYB_LCY);
 #else
@@ -507,7 +507,7 @@ void range_separation(int func_id, double & omega, dou
       throw std::runtime_error(oss.str());
     }
 
-#if XC_MAJOR_VERSION >= 6
+#if XC_MAJOR_VERSION > 6
     switch(xc_hyb_type(&func)) {
     case(XC_HYB_SEMILOCAL):
       break;
