--- avidemux/ADM_libraries/ADM_libtwolame/bitbuffer.h.orig	2006-03-19 00:36:30.000000000 +0300
+++ avidemux/ADM_libraries/ADM_libtwolame/bitbuffer.h	2009-04-16 22:26:17.000000000 +0400
@@ -40,7 +40,7 @@
 void buffer_deinit( bit_stream ** bs );
 
 void buffer_put1bit (bit_stream *, int);
-inline void buffer_putbits (bit_stream *, unsigned int, int);
+void buffer_putbits (bit_stream *, unsigned int, int);
 unsigned long buffer_sstell (bit_stream *);
 
 #endif
