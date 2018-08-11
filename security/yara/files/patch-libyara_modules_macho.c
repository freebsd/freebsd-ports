--- libyara/modules/macho.c.orig	2018-08-06 13:28:12 UTC
+++ libyara/modules/macho.c
@@ -262,7 +262,7 @@ MACHO_HANDLE_MAIN(be)
 #define MACHO_HANDLE_SEGMENT(bits,bo)                                          \
 void macho_handle_segment_##bits##_##bo(                                       \
     const uint8_t* command,                                                    \
-    const uint64_t i,                                                          \
+    const unsigned i,                                                          \
     YR_OBJECT* object)                                                         \
 {                                                                              \
   yr_segment_command_##bits##_t* sg = (yr_segment_command_##bits##_t*)command; \
