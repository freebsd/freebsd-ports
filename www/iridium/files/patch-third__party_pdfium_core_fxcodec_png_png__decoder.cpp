--- third_party/pdfium/core/fxcodec/png/png_decoder.cpp.orig	2025-06-19 07:37:57 UTC
+++ third_party/pdfium/core/fxcodec/png/png_decoder.cpp
@@ -52,8 +52,8 @@ void _png_load_bmp_attribute(png_structp png_ptr,
                              CFX_DIBAttribute* pAttribute) {
   if (pAttribute) {
 #if defined(PNG_pHYs_SUPPORTED)
-    pAttribute->xdpi_ = png_get_x_pixels_per_meter(png_ptr, info_ptr);
-    pAttribute->ydpi_ = png_get_y_pixels_per_meter(png_ptr, info_ptr);
+    pAttribute->x_dpi_ = png_get_x_pixels_per_meter(png_ptr, info_ptr);
+    pAttribute->y_dpi_ = png_get_y_pixels_per_meter(png_ptr, info_ptr);
     png_uint_32 res_x, res_y;
     int unit_type;
     png_get_pHYs(png_ptr, info_ptr, &res_x, &res_y, &unit_type);
