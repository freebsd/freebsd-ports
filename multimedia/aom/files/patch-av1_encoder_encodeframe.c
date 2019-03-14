av1/encoder/encodeframe.c:3873:33: error: use of undeclared identifier 'ref_frame_flag_list'; did you mean 'av1_ref_frame_flag_list'?
  assert(cpi->ref_frame_flags & ref_frame_flag_list[LAST_FRAME] ||
                                ^~~~~~~~~~~~~~~~~~~
                                av1_ref_frame_flag_list
/usr/include/assert.h:54:21: note: expanded from macro 'assert'
#define assert(e)       ((e) ? (void)0 : __assert(__func__, __FILE__, \
                          ^
av1/encoder/encoder.h:1282:22: note: 'av1_ref_frame_flag_list' declared here
static const uint8_t av1_ref_frame_flag_list[REF_FRAMES] = { 0,
                     ^
av1/encoder/encodeframe.c:3874:33: error: use of undeclared identifier 'ref_frame_flag_list'; did you mean 'av1_ref_frame_flag_list'?
         cpi->ref_frame_flags & ref_frame_flag_list[ALTREF_FRAME]);
                                ^~~~~~~~~~~~~~~~~~~
                                av1_ref_frame_flag_list
/usr/include/assert.h:54:21: note: expanded from macro 'assert'
#define assert(e)       ((e) ? (void)0 : __assert(__func__, __FILE__, \
                          ^
av1/encoder/encoder.h:1282:22: note: 'av1_ref_frame_flag_list' declared here
static const uint8_t av1_ref_frame_flag_list[REF_FRAMES] = { 0,
                     ^

--- av1/encoder/encodeframe.c.orig	2019-03-13 23:38:12 UTC
+++ av1/encoder/encodeframe.c
@@ -3870,8 +3870,8 @@ static void firstpass_simple_motion_search_features(
     AV1_COMP *const cpi, MACROBLOCK *x, PC_TREE *pc_tree, int mi_row,
     int mi_col, BLOCK_SIZE bsize, float *features) {
   assert(mi_size_wide[bsize] == mi_size_high[bsize]);
-  assert(cpi->ref_frame_flags & ref_frame_flag_list[LAST_FRAME] ||
-         cpi->ref_frame_flags & ref_frame_flag_list[ALTREF_FRAME]);
+  assert(cpi->ref_frame_flags & av1_ref_frame_flag_list[LAST_FRAME] ||
+         cpi->ref_frame_flags & av1_ref_frame_flag_list[ALTREF_FRAME]);
 
   // Setting up motion search
   const int ref_list[] = { LAST_FRAME, ALTREF_FRAME };
