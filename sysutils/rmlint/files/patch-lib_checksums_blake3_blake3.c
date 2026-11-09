--- lib/checksums/blake3/blake3.c.orig	2026-11-09 06:56:39 UTC
+++ lib/checksums/blake3/blake3.c
@@ -359,6 +359,7 @@ compress_subtree_to_parent_node(const uint8_t *input, 
   size_t num_cvs = blake3_compress_subtree_wide(input, input_len, key,
                                                 chunk_counter, flags, cv_array, use_tbb);
   assert(num_cvs <= MAX_SIMD_DEGREE_OR_2);
+  (void)num_cvs;
   // The following loop never executes when MAX_SIMD_DEGREE_OR_2 is 2, because
   // as we just asserted, num_cvs will always be <=2 in that case. But GCC
   // (particularly GCC 8.5) can't tell that it never executes, and if NDEBUG is
