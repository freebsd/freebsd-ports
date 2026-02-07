--- src/layer/x86/gemm_int8.h.orig	2026-01-13 02:57:43 UTC
+++ src/layer/x86/gemm_int8.h
@@ -1,5 +1,6 @@
 // Copyright 2024 Tencent
 // SPDX-License-Identifier: BSD-3-Clause
+#include "avx512_mathfun.h"
 
 #if NCNN_RUNTIME_CPU && NCNN_AVX512VNNI && __AVX512F__ && !__AVX512VNNI__
 void pack_A_tile_int8_avx512vnni(const Mat& A, Mat& AT, int i, int max_ii, int k, int max_kk);
