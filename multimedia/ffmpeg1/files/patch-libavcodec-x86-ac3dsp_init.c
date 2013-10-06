--- libavcodec/x86/ac3dsp_init.c.orig	2013-08-27 02:13:46.000000000 +0200
+++ libavcodec/x86/ac3dsp_init.c	2013-10-06 18:08:54.000000000 +0200
@@ -70,11 +70,11 @@ extern void ff_ac3_extract_exponents_sss
         "shufps     $0, %%xmm6, %%xmm6          \n"             \
         "shufps     $0, %%xmm7, %%xmm7          \n"             \
         "1:                                     \n"             \
-        "movaps       (%0, %2), %%xmm0          \n"             \
-        "movaps       (%0, %3), %%xmm1          \n"             \
-        "movaps       (%0, %4), %%xmm2          \n"             \
-        "movaps       (%0, %5), %%xmm3          \n"             \
-        "movaps       (%0, %6), %%xmm4          \n"             \
+        "movups       (%0, %2), %%xmm0          \n"             \
+        "movups       (%0, %3), %%xmm1          \n"             \
+        "movups       (%0, %4), %%xmm2          \n"             \
+        "movups       (%0, %5), %%xmm3          \n"             \
+        "movups       (%0, %6), %%xmm4          \n"             \
         "mulps          %%xmm5, %%xmm0          \n"             \
         "mulps          %%xmm6, %%xmm1          \n"             \
         "mulps          %%xmm5, %%xmm2          \n"             \
@@ -85,8 +85,8 @@ extern void ff_ac3_extract_exponents_sss
         "addps          %%xmm3, %%xmm0          \n"             \
         "addps          %%xmm4, %%xmm2          \n"             \
    mono("addps          %%xmm2, %%xmm0          \n")            \
-        "movaps         %%xmm0, (%0, %2)        \n"             \
- stereo("movaps         %%xmm2, (%0, %3)        \n")            \
+        "movups         %%xmm0, (%0, %2)        \n"             \
+ stereo("movups         %%xmm2, (%0, %3)        \n")            \
         "add               $16, %0              \n"             \
         "jl                 1b                  \n"             \
         : "+&r"(i)                                              \
@@ -106,24 +106,26 @@ extern void ff_ac3_extract_exponents_sss
         "mov              %5, %2            \n"                 \
         "1:                                 \n"                 \
         "mov -%c7(%6, %2, %c8), %3          \n"                 \
-        "movaps     (%3, %0), %%xmm0        \n"                 \
+        "movups     (%3, %0), %%xmm0        \n"                 \
  stereo("movaps       %%xmm0, %%xmm1        \n")                \
         "mulps        %%xmm4, %%xmm0        \n"                 \
  stereo("mulps        %%xmm5, %%xmm1        \n")                \
         "2:                                 \n"                 \
         "mov   (%6, %2, %c8), %1            \n"                 \
-        "movaps     (%1, %0), %%xmm2        \n"                 \
+        "movups     (%1, %0), %%xmm2        \n"                 \
  stereo("movaps       %%xmm2, %%xmm3        \n")                \
-        "mulps   (%4, %2, 8), %%xmm2        \n"                 \
- stereo("mulps 16(%4, %2, 8), %%xmm3        \n")                \
+        "movups  (%4, %2, 8), %%xmm4        \n"                 \
+        "mulps        %%xmm4, %%xmm2        \n"                 \
+ stereo("movups 16(%4, %2, 8), %%xmm4       \n")                \
+ stereo("mulps        %%xmm4, %%xmm3        \n")                \
         "addps        %%xmm2, %%xmm0        \n"                 \
  stereo("addps        %%xmm3, %%xmm1        \n")                \
         "add              $4, %2            \n"                 \
         "jl               2b                \n"                 \
         "mov              %5, %2            \n"                 \
  stereo("mov   (%6, %2, %c8), %1            \n")                \
-        "movaps       %%xmm0, (%3, %0)      \n"                 \
- stereo("movaps       %%xmm1, (%1, %0)      \n")                \
+        "movups       %%xmm0, (%3, %0)      \n"                 \
+ stereo("movups       %%xmm1, (%1, %0)      \n")                \
         "add             $16, %0            \n"                 \
         "jl               1b                \n"                 \
         : "+&r"(i), "=&r"(j), "=&r"(k), "=&r"(m)                \
@@ -152,7 +154,7 @@ static void ac3_downmix_sse(float **samp
                matrix_cmp[3][0] == matrix_cmp[4][0]) {
         MIX5(IF1, IF0);
     } else {
-        DECLARE_ALIGNED(16, float, matrix_simd)[AC3_MAX_CHANNELS][2][4];
+        float matrix_simd[AC3_MAX_CHANNELS][2][4];
         float *samp[AC3_MAX_CHANNELS];
 
         for (j = 0; j < in_ch; j++)
@@ -166,8 +168,8 @@ static void ac3_downmix_sse(float **samp
             "movss    4(%2, %0), %%xmm5         \n"
             "shufps          $0, %%xmm4, %%xmm4 \n"
             "shufps          $0, %%xmm5, %%xmm5 \n"
-            "movaps      %%xmm4,   (%1, %0, 4)  \n"
-            "movaps      %%xmm5, 16(%1, %0, 4)  \n"
+            "movups      %%xmm4,   (%1, %0, 4)  \n"
+            "movups      %%xmm5, 16(%1, %0, 4)  \n"
             "jg              1b                 \n"
             : "+&r"(j)
             : "r"(matrix_simd), "r"(matrix)
