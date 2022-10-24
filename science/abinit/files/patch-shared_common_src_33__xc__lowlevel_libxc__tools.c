--- shared/common/src/33_xc_lowlevel/libxc_tools.c.orig	2021-11-09 07:25:16 UTC
+++ shared/common/src/33_xc_lowlevel/libxc_tools.c
@@ -70,8 +70,8 @@ void xc_get_family_constants(int *xc_cst_family_unknow
  *xc_cst_family_mgga     = XC_FAMILY_MGGA;
  *xc_cst_family_lca      = XC_FAMILY_LCA;
  *xc_cst_family_oep      = XC_FAMILY_OEP;
-#if ( XC_MAJOR_VERSION > 5 ) 
-/* ==== libXC v6.0 and later ==== */
+#if ( XC_MAJOR_VERSION > 6 ) 
+/* ==== After libXC v6.0 ==== */
  *xc_cst_family_hyb_gga  = -11;
  *xc_cst_family_hyb_mgga = -11;
 #else
@@ -137,8 +137,8 @@ void xc_get_hybrid_constants(int *xc_cst_hyb_none,
 							 int *xc_cst_hyb_double_hybrid,
 							 int *xc_cst_hyb_mixture)
 {
-#if ( XC_MAJOR_VERSION > 5 ) 
-/* ==== libXC v6.0 and later ==== */
+#if ( XC_MAJOR_VERSION > 6 ) 
+/* ==== After libXC v6.0 ==== */
  *xc_cst_hyb_none          = XC_HYB_NONE;
  *xc_cst_hyb_fock          = XC_HYB_FOCK;
  *xc_cst_hyb_pt2           = XC_HYB_PT2;
@@ -348,8 +348,8 @@ void xc_func_set_density_threshold(XC(func_type) *xc_f
  * ===============================================================
  */
 int xc_func_is_hybrid_from_id(int func_id)
-#if ( XC_MAJOR_VERSION > 5 ) 
-/* ==== libXC v6.0 and later ==== */
+#if ( XC_MAJOR_VERSION > 6 ) 
+/* ==== After libXC v6.0 ==== */
  {xc_func_type func; int result=0;
   if(xc_func_init(&func,func_id,XC_UNPOLARIZED)==0)
     {if (func.hyb_number_terms>0)
