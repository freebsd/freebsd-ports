--- shared/common/src/33_xc_lowlevel/libxc_tools.c.orig	2023-04-24 13:01:07 UTC
+++ shared/common/src/33_xc_lowlevel/libxc_tools.c
@@ -73,7 +73,7 @@ void xc_get_family_constants(int *xc_cst_family_unknow
  *xc_cst_family_oep      = XC_FAMILY_OEP;
  *xc_cst_family_hyb_gga  = XC_FAMILY_HYB_GGA;
  *xc_cst_family_hyb_mgga = XC_FAMILY_HYB_MGGA;
-#if ( XC_MAJOR_VERSION > 5 )
+#if ( XC_MAJOR_VERSION > 6 )
 /* ==== libXC v6.0 and later ==== */
  *xc_cst_family_hyb_lda  = XC_FAMILY_HYB_LDA;
 #else
@@ -364,7 +364,7 @@ void xc_func_set_grad_sig_threshold(XC(func_type) *xc_
 int xc_func_is_hybrid_from_id(int func_id)
 /* ==== Before libXC v6.0 ==== */
  {int family; family=xc_family_from_id(func_id, NULL, NULL);
-#if ( XC_MAJOR_VERSION > 5 )
+#if ( XC_MAJOR_VERSION > 6 )
 /* ==== libXC v6.0 and later ==== */
   if (family==XC_FAMILY_HYB_GGA || family==XC_FAMILY_HYB_MGGA || family==XC_FAMILY_HYB_LDA)
    {return 1;}
