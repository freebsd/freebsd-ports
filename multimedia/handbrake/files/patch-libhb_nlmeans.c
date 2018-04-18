--- libhb/nlmeans.c.orig	2017-10-05 21:17:34 UTC
+++ libhb/nlmeans.c
@@ -787,7 +787,7 @@ static int nlmeans_init(hb_filter_object
     NLMeansFunctions *functions = &pv->functions;
 
     functions->build_integral = build_integral_scalar;
-#if defined(ARCH_X86)
+#if defined(ARCH_X86) && defined(__X86_64)
     nlmeans_init_x86(functions);
 #endif
 
