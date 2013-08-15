--- src/computefourier-3.0.cc.orig	2013-06-13 08:12:26.000000000 -0400
+++ src/computefourier-3.0.cc	2013-08-10 17:02:52.000000000 -0400
@@ -416,27 +416,64 @@
 
   __m128d t1r = _mm_mul_pd(v1r, ab31);
   __m128d t1i = _mm_mul_pd(v1i, ba31);
+
+#ifdef __SSE3__
   __m128d remove1 = _mm_addsub_pd(t1r, t1i);
+#else
+__m128i mask_fliplo = _mm_set_epi32(0, 0, 0x80000000, 0);
+__m128d t1i_fliplo = _mm_xor_pd(t1i, _mm_castsi128_pd(mask_fliplo));
+__m128d remove1 = _mm_add_pd(t1r, t1i_fliplo);
+#endif
 
   __m128d t2r = _mm_mul_pd(v1r, ab32);
   __m128d t2i = _mm_mul_pd(v1i, ba32);
+
+#ifdef __SSE3__
   __m128d remove2 = _mm_addsub_pd(t2r, t2i);
+#else
+__m128d t2i_fliplo = _mm_xor_pd(t2i, _mm_castsi128_pd(mask_fliplo));
+__m128d remove2 = _mm_add_pd(t2r, t2i_fliplo);
+#endif
 
   __m128d t3r = _mm_mul_pd(v1r, ab33);
   __m128d t3i = _mm_mul_pd(v1i, ba33);
+  
+#ifdef __SSE3__
   __m128d remove3 = _mm_addsub_pd(t3r, t3i);
+#else
+__m128d t3i_fliplo = _mm_xor_pd(t3i, _mm_castsi128_pd(mask_fliplo));
+__m128d remove3 = _mm_add_pd(t3r, t3i_fliplo);
+#endif
 
   __m128d t4r = _mm_mul_pd(v2r, ab31);
   __m128d t4i = _mm_mul_pd(v2i, ba31);
+
+#ifdef __SSE3__
   __m128d remove4 = _mm_addsub_pd(t4r, t4i);
+#else
+__m128d t4i_fliplo = _mm_xor_pd(t4i, _mm_castsi128_pd(mask_fliplo));
+__m128d remove4 = _mm_add_pd(t4r, t4i_fliplo);
+#endif
 
   __m128d t5r = _mm_mul_pd(v2r, ab32);
   __m128d t5i = _mm_mul_pd(v2i, ba32);
+
+#ifdef __SSE3__
   __m128d remove5 = _mm_addsub_pd(t5r, t5i);
+#else
+__m128d t5i_fliplo = _mm_xor_pd(t5i, _mm_castsi128_pd(mask_fliplo));
+__m128d remove5 = _mm_add_pd(t5r, t5i_fliplo);
+#endif
 
   __m128d t6r = _mm_mul_pd(v2r, ab33);
   __m128d t6i = _mm_mul_pd(v2i, ba33);
+
+#ifdef __SSE3__
   __m128d remove6 = _mm_addsub_pd(t6r, t6i);
+#else
+__m128d t6i_fliplo = _mm_xor_pd(t6i, _mm_castsi128_pd(mask_fliplo));
+__m128d remove6 = _mm_add_pd(t6r, t6i_fliplo);
+#endif
 
   FLOPCOUNT_INCREMENT(6 * (4 + 2));
 
@@ -524,11 +561,28 @@
       __m128d a3b3_sq = _mm_mul_pd(a3b3, a3b3);
       FLOPCOUNT_INCREMENT(8);
 
+#ifdef __SSE3__
       __m128d c0c1 = _mm_hadd_pd(a0b0_sq, a1b1_sq);
       __m128d c2c3 = _mm_hadd_pd(a2b2_sq, a3b3_sq);
+#else
+      __m128d c0c1_lo = _mm_shuffle_pd(a0b0_sq, a1b1_sq, 0);
+      __m128d c0c1_hi = _mm_shuffle_pd(a0b0_sq, a1b1_sq, 3);
+      __m128d c0c1 = _mm_add_pd(c0c1_lo, c0c1_hi);
+      __m128d c2c3_lo = _mm_shuffle_pd(a2b2_sq, a3b3_sq, 0);
+      __m128d c2c3_hi = _mm_shuffle_pd(a2b2_sq, a3b3_sq, 3);
+      __m128d c2c3 = _mm_add_pd(c2c3_lo, c2c3_hi);
+#endif
+
       FLOPCOUNT_INCREMENT(4);
 
+#ifdef __SSE3__
       __m128d zbc = _mm_hadd_pd(c0c1, c2c3);
+#else
+      __m128d zbc_lo = _mm_shuffle_pd(c0c1, c2c3, 0);
+      __m128d zbc_hi = _mm_shuffle_pd(c0c1, c2c3, 3);
+      __m128d zbc = _mm_add_pd(zbc_lo, zbc_hi);
+#endif
+
       FLOPCOUNT_INCREMENT(1);
 
       _mm_store_pd(zero_buck_check, zbc);
@@ -681,13 +735,35 @@
       __m128d a3b3_sq = _mm_mul_pd(a3b3, a3b3);
       FLOPCOUNT_INCREMENT(8);
 
+#ifdef __SSE3__
       __m128d c0c1 = _mm_hadd_pd(a0b0_sq, a1b1_sq);
+#else
+      __m128d c0c1_lo = _mm_shuffle_pd(a0b0_sq, a1b1_sq, 0);
+      __m128d c0c1_hi = _mm_shuffle_pd(a0b0_sq, a1b1_sq, 3);
+      __m128d c0c1 = _mm_add_pd(c0c1_lo, c0c1_hi);
+#endif
+
       __m128d c0c1_normed = _mm_mul_pd(c0c1, norm2vec);
+      
+#ifdef __SSE3__
       __m128d c2c3 = _mm_hadd_pd(a2b2_sq, a3b3_sq);
+#else
+      __m128d c2c3_lo = _mm_shuffle_pd(a2b2_sq, a3b3_sq, 0);
+      __m128d c2c3_hi = _mm_shuffle_pd(a2b2_sq, a3b3_sq, 3);
+      __m128d c2c3 = _mm_add_pd(c2c3_lo, c2c3_hi);
+#endif
+
       __m128d c2c3_normed = _mm_mul_pd(c2c3, norm2vec);
       FLOPCOUNT_INCREMENT(8);
 
+#ifdef __SSE3__
       __m128d zbc = _mm_hadd_pd(c0c1_normed, c2c3_normed);
+#else
+      __m128d zbc_lo = _mm_shuffle_pd(c0c1_normed, c2c3_normed, 0);
+      __m128d zbc_hi = _mm_shuffle_pd(c0c1_normed, c2c3_normed, 3);
+      __m128d zbc = _mm_add_pd(zbc_lo, zbc_hi);
+#endif
+
       FLOPCOUNT_INCREMENT(1);
 
       _mm_store_pd(zero_buck_check, zbc);
