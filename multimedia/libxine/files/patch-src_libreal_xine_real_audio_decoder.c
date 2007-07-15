--- src/libreal/xine_real_audio_decoder.c.orig	Tue Apr 17 10:00:50 2007
+++ src/libreal/xine_real_audio_decoder.c	Sun Jul  1 14:24:05 2007
@@ -47,6 +47,14 @@
 
 #include "real_common.h"
 
+#if defined(__FreeBSD__)
+void ___brk_addr(void) {exit(0);}
+void __ctype_b(void) {exit(0);}
+char **__environ={NULL};
+#undef stderr
+FILE *stderr=NULL;
+#endif
+
 typedef struct {
   audio_decoder_class_t   decoder_class;
 
