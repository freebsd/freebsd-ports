https://github.com/scimmia9286/aribb24/commit/58a34b8fabf4d0e9e1984fb603a97f52fb934a09
--- src/drcs.h.orig	2019-09-16 15:57:19 UTC
+++ src/drcs.h
@@ -77,6 +77,6 @@ typedef struct drcs_data_s
 
 bool apply_drcs_conversion_table( arib_instance_t * );
 bool load_drcs_conversion_table( arib_instance_t * );
-void save_drcs_pattern( arib_instance_t *, int, int, int, const int8_t* );
+void save_drcs_pattern( arib_instance_t *, int, int, int, const int8_t*, int16_t );
 
 #endif
