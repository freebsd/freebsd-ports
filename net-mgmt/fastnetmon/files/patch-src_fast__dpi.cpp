--- src/fast_dpi.cpp.orig	2016-06-22 05:22:26 UTC
+++ src/fast_dpi.cpp
@@ -35,7 +35,7 @@ struct ndpi_detection_module_struct* ini
     u_int32_t detection_tick_resolution = 1000;
     
     struct ndpi_detection_module_struct* my_ndpi_struct =
-        ndpi_init_detection_module(detection_tick_resolution, malloc, free, debug_printf);
+        ndpi_init_detection_module();
 
     if (my_ndpi_struct == NULL) {
         // printf("Can't init nDPI");
