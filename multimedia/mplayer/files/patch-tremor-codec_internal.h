--- tremor/codec_internal.h.orig	Sun Aug 20 11:04:15 2006
+++ tremor/codec_internal.h	Sun Aug 20 11:06:05 2006
@@ -17,6 +17,8 @@
 
 #include "codebook.h"
 
+void *_vorbis_block_alloc(vorbis_block *vb, long bytes);
+
 typedef void vorbis_look_mapping;
 typedef void vorbis_look_floor;
 typedef void vorbis_look_residue;
