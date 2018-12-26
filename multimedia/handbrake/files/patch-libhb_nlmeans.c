--- libhb/nlmeans.c.orig	2018-06-17 04:23:34 UTC
+++ libhb/nlmeans.c
@@ -898,7 +898,7 @@ static int nlmeans_init(hb_filter_object_t *filter,
     NLMeansFunctions *functions = &pv->functions;
 
     functions->build_integral = build_integral_scalar;
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && defined(__X86_64)
     nlmeans_init_x86(functions);
 #endif
 
