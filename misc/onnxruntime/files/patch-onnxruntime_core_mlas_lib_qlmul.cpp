--- onnxruntime/core/mlas/lib/qlmul.cpp.orig	2026-01-02 14:18:24 UTC
+++ onnxruntime/core/mlas/lib/qlmul.cpp
@@ -325,7 +325,7 @@ MlasQLinearMulKernel(
     }
 
     while (N >= 4) {
-#if defined(_AIX) && defined(__clang__)
+#if (defined(_AIX) || defined(__FreeBSD__)) && defined(__clang__)
         __vector int IntegerAVector {InputA[0], InputA[1], InputA[2], InputA[3]};
 #else
         __vector int32_t  IntegerAVector {InputA[0], InputA[1], InputA[2], InputA[3]};
@@ -334,7 +334,7 @@ MlasQLinearMulKernel(
         auto ValueAVector = vec_mul(ScaleAVector, vec_ctf(IntegerVector, 0));
 
         if (!IsScalarB) {
-#if defined(_AIX) && defined(__clang__)
+#if (defined(_AIX) || defined(__FreeBSD__)) && defined(__clang__)
             __vector int  IntegerBVector {InputB[0], InputB[1], InputB[2], InputB[3]};
 #else
             __vector int32_t  IntegerBVector {InputB[0], InputB[1], InputB[2], InputB[3]};
