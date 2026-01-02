--- onnxruntime/core/mlas/lib/power/qgemm_kernel_power10.cpp.orig	2026-01-02 14:17:54 UTC
+++ onnxruntime/core/mlas/lib/power/qgemm_kernel_power10.cpp
@@ -874,14 +874,14 @@ MlasQgemmStoreVectorMMA
 {
     size_t RowCount;
     __vector signed int vsum0, vsum1, vsum2, vsum3;
-#if defined(_AIX) && defined(__clang__)
+#if (defined(_AIX) || defined(__FreeBSD__)) && defined(__clang__)
     __vector signed int columnsum = *reinterpret_cast<const __vector int *>(&ColumnSumBuffer[pos]);
 #else
     __vector signed int columnsum = *reinterpret_cast<const __vector int32_t *>(&ColumnSumBuffer[pos]);
 #endif
     C += VectorCount;
     if (ZeroPointB != nullptr) {
-#if defined(_AIX) && defined(__clang__)
+#if (defined(_AIX) || defined(__FreeBSD__)) && defined(__clang__)
         __vector signed int zeropoint = *reinterpret_cast<const __vector int *>(&ZeroPointB[pos]);
 #else
         __vector signed int zeropoint = *reinterpret_cast<const __vector int32_t *>(&ZeroPointB[pos]);
