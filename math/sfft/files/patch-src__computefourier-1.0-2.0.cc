--- src/computefourier-1.0-2.0.cc.orig	2013-06-13 08:12:25.000000000 -0400
+++ src/computefourier-1.0-2.0.cc	2013-08-09 00:26:54.000000000 -0400
@@ -248,8 +248,13 @@
           __m128d ad_bc = _mm_mul_pd(ab, dc);
           __m128d ac_mbd = _mm_mul_pd(ac_bd, signs);
 
+#ifdef __SSE3__
           __m128d ab_times_cd = _mm_hadd_pd(ac_mbd, ad_bc);
-
+#else
+          __m128d ab_times_cd_lo = _mm_shuffle_pd(ac_mbd, ad_bc, 0);
+          __m128d ab_times_cd_hi = _mm_shuffle_pd(ac_mbd, ad_bc, 3);
+          __m128d ab_times_cd = _mm_add_pd(ab_times_cd_lo, ab_times_cd_hi);
+#endif
           unsigned int i_mod_B_p_offset = (i & B2_m_1) + offset;
           __m128d xy = _mm_load_pd(d_x_sampt + i_mod_B_p_offset);
           __m128d st = _mm_add_pd(xy, ab_times_cd);
@@ -283,7 +288,13 @@
       __m128d ab_square = _mm_mul_pd(ab, ab);
       __m128d cd_square = _mm_mul_pd(cd, cd);
 
+#ifdef __SSE3__
       __m128d r = _mm_hadd_pd(ab_square, cd_square);
+#else
+      __m128d r_lo = _mm_shuffle_pd(ab_square, cd_square, 0);
+      __m128d r_hi = _mm_shuffle_pd(ab_square, cd_square, 3);
+      __m128d r = _mm_add_pd(r_lo, r_hi);
+#endif
 
       _mm_store_pd(samples + j, r);
     }
@@ -390,11 +401,23 @@
           __m128d ad_bc = _mm_mul_pd(ab, dc);
           __m128d mad_bc = _mm_mul_pd(ad_bc, signs);
 
+#ifdef __SSE3__
           __m128d acpbd_bcmad = _mm_hadd_pd(ac_bd, mad_bc);
+#else
+          __m128d acpbd_bcmad_lo = _mm_shuffle_pd(ac_bd, mad_bc, 0);
+          __m128d acpbd_bcmad_hi = _mm_shuffle_pd(ac_bd, mad_bc, 3);
+          __m128d acpbd_bcmad = _mm_add_pd(acpbd_bcmad_lo, acpbd_bcmad_hi);
+#endif
 
           __m128d cd_squares = _mm_mul_pd(cd, cd);
+
+#ifdef __SSE3__
           __m128d cd_squares_sum =
             _mm_hadd_pd(cd_squares, cd_squares);
+#else
+          __m128d cd_squares_flip = _mm_shuffle_pd(cd_squares, cd_squares, 1);
+          __m128d cd_squares_sum = _mm_add_pd(cd_squares, cd_squares_flip);
+#endif
 
           __m128d r = _mm_div_pd(acpbd_bcmad, cd_squares_sum);
 
