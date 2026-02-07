--- shared/libpaw/src/libpaw_libxc.c.orig	2024-04-12 04:50:51 UTC
+++ shared/libpaw/src/libpaw_libxc.c
@@ -71,7 +71,7 @@ void libpaw_xc_get_family_constants(int *xc_cst_family
  *xc_cst_family_oep      = XC_FAMILY_OEP;
  *xc_cst_family_hyb_gga  = XC_FAMILY_HYB_GGA;
  *xc_cst_family_hyb_mgga = XC_FAMILY_HYB_MGGA;
-#if ( XC_MAJOR_VERSION > 5 )
+#if ( XC_MAJOR_VERSION > 6 )
  /* ==== libXC v6.0 and later ==== */
  *xc_cst_family_hyb_lda  = XC_FAMILY_HYB_LDA;
 #else
@@ -353,7 +353,7 @@ int libpaw_xc_func_is_hybrid_from_id(int func_id)
  */
 int libpaw_xc_func_is_hybrid_from_id(int func_id)
  {int family; family=xc_family_from_id(func_id, NULL, NULL);
-#if ( XC_MAJOR_VERSION > 5 )
+#if ( XC_MAJOR_VERSION > 6 )
 /* ==== libXC v6.0 and later ==== */
   if (family==XC_FAMILY_HYB_GGA || family==XC_FAMILY_HYB_MGGA || family==XC_FAMILY_HYB_LDA)
    {return 1;}
