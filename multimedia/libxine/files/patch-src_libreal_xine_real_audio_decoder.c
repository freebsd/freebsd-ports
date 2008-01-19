--- src/libreal/xine_real_audio_decoder.c.orig	2008-01-01 22:30:08.000000000 +0900
+++ src/libreal/xine_real_audio_decoder.c	2008-01-20 01:44:15.000000000 +0900
@@ -45,6 +45,19 @@
 
 #include "real_common.h"
 
+#if defined(__FreeBSD__)
+void ___brk_addr(void) {exit(0);}
+void __ctype_b(void) {exit(0);}
+void __strtod_internal(void) {exit(0);}
+void __strtold_internal(void) {exit(0);}
+void __strtof_internal(void) {exit(0);}
+void __errno_location(void) {exit(0);}
+void dl_iterate_phdr(void) {exit(0);}
+char **__environ={NULL};
+#undef stderr
+FILE *stderr=NULL;
+#endif
+
 typedef struct {
   audio_decoder_class_t   decoder_class;
 
