--- libavcodec/vorbis_dec.c.orig	2010-07-02 19:05:36.000000000 +0200
+++ libavcodec/vorbis_dec.c	2010-09-16 17:32:17.754521304 +0200
@@ -81,7 +81,7 @@
         } t0;
         struct vorbis_floor1_s {
             uint_fast8_t partitions;
-            uint_fast8_t partition_class[32];
+            uint8_t      partition_class[32];
             uint_fast8_t class_dimensions[16];
             uint_fast8_t class_subclasses[16];
             uint_fast8_t class_masterbook[16];
@@ -97,13 +97,13 @@
     uint_fast16_t type;
     uint_fast32_t begin;
     uint_fast32_t end;
-    uint_fast32_t partition_size;
+    unsigned      partition_size;
     uint_fast8_t  classifications;
     uint_fast8_t  classbook;
     int_fast16_t  books[64][8];
     uint_fast8_t  maxpass;
     uint_fast16_t ptns_to_read;
-    uint_fast8_t *classifs;
+    uint8_t *classifs;
 } vorbis_residue;
 
 typedef struct {
@@ -467,7 +467,7 @@
 static int vorbis_parse_setup_hdr_floors(vorbis_context *vc)
 {
     GetBitContext *gb = &vc->gb;
-    uint_fast16_t i,j,k;
+    int i,j,k;
 
     vc->floor_count = get_bits(gb, 6) + 1;
 
@@ -655,7 +655,7 @@
         if (res_setup->begin>res_setup->end ||
             res_setup->end > vc->avccontext->channels * vc->blocksize[1] / (res_setup->type == 2 ? 1 : 2) ||
             (res_setup->end-res_setup->begin) / res_setup->partition_size > V_MAX_PARTITIONS) {
-            av_log(vc->avccontext, AV_LOG_ERROR, "partition out of bounds: type, begin, end, size, blocksize: %"PRIdFAST16", %"PRIdFAST32", %"PRIdFAST32", %"PRIdFAST32", %"PRIdFAST32"\n", res_setup->type, res_setup->begin, res_setup->end, res_setup->partition_size, vc->blocksize[1] / 2);
+            av_log(vc->avccontext, AV_LOG_ERROR, "partition out of bounds: type, begin, end, size, blocksize: %"PRIdFAST16", %"PRIdFAST32", %"PRIdFAST32", %u, %"PRIdFAST32"\n", res_setup->type, res_setup->begin, res_setup->end, res_setup->partition_size, vc->blocksize[1] / 2);
             return -1;
         }
 
@@ -667,6 +667,8 @@
         res_setup->classifs = av_malloc(res_setup->ptns_to_read *
                                         vc->audio_channels *
                                         sizeof(*res_setup->classifs));
+        if (!res_setup->classifs)
+            return AVERROR(ENOMEM);
 
         AV_DEBUG("    begin %d end %d part.size %d classif.s %d classbook %d \n", res_setup->begin, res_setup->end, res_setup->partition_size,
           res_setup->classifications, res_setup->classbook);
@@ -1267,7 +1269,7 @@
     GetBitContext *gb = &vc->gb;
     uint_fast8_t c_p_c = vc->codebooks[vr->classbook].dimensions;
     uint_fast16_t ptns_to_read = vr->ptns_to_read;
-    uint_fast8_t *classifs = vr->classifs;
+    uint8_t *classifs = vr->classifs;
     uint_fast8_t pass;
     uint_fast8_t ch_used;
     uint_fast8_t i,j,l;
