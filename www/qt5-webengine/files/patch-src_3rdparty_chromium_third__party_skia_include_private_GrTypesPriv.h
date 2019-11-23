--- src/3rdparty/chromium/third_party/skia/include/private/GrTypesPriv.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/include/private/GrTypesPriv.h
@@ -65,9 +65,6 @@ enum GrPixelConfig {
 static const int kGrPixelConfigCnt = kLast_GrPixelConfig + 1;
 
 // Aliases for pixel configs that match skia's byte order.
-#ifndef SK_CPU_LENDIAN
-#error "Skia gpu currently assumes little endian"
-#endif
 #if SK_PMCOLOR_BYTE_ORDER(B,G,R,A)
 static const GrPixelConfig kSkia8888_GrPixelConfig = kBGRA_8888_GrPixelConfig;
 #elif SK_PMCOLOR_BYTE_ORDER(R,G,B,A)
