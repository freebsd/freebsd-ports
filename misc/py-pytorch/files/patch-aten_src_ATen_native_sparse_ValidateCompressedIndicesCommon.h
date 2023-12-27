--- aten/src/ATen/native/sparse/ValidateCompressedIndicesCommon.h.orig	2023-12-15 02:03:27 UTC
+++ aten/src/ATen/native/sparse/ValidateCompressedIndicesCommon.h
@@ -40,7 +40,7 @@ INVARIANT_CHECK_FUNC_API
 // use `cidx/idx` to refer to `compressed_indices/plain_indices` respectively.
 
 INVARIANT_CHECK_FUNC_API
-_assert(const bool cond, const char* const message) {
+__assert(const bool cond, const char* const message) {
 #ifdef GPUCC
   CUDA_KERNEL_ASSERT(cond && message);
 #else
@@ -58,9 +58,9 @@ INVARIANT_CHECK_FUNC_API _check_first_cidx_is_zero(
     const index_t& zero) {
   const bool invariant = cidx == zero;
   if (cdim_name == CDimName::CRow) {
-    _assert(invariant, "`crow_indices[..., 0] == 0` is not satisfied.");
+    __assert(invariant, "`crow_indices[..., 0] == 0` is not satisfied.");
   } else {
-    _assert(invariant, "`ccol_indices[..., 0] == 0` is not satisfied.");
+    __assert(invariant, "`ccol_indices[..., 0] == 0` is not satisfied.");
   }
 }
 
@@ -72,9 +72,9 @@ INVARIANT_CHECK_FUNC_API _check_last_cidx_is_nnz(
     const index_t& nnz) {
   const bool invariant = cidx == nnz;
   if (cdim_name == CDimName::CRow) {
-    _assert(invariant, "`crow_indices[..., -1] == nnz` is not satisfied.");
+    __assert(invariant, "`crow_indices[..., -1] == nnz` is not satisfied.");
   } else {
-    _assert(invariant, "`ccol_indices[..., -1] == nnz` is not satisfied.");
+    __assert(invariant, "`ccol_indices[..., -1] == nnz` is not satisfied.");
   }
 }
 
@@ -89,11 +89,11 @@ INVARIANT_CHECK_FUNC_API _check_cidx_nondecreasing_loc
   const auto s_cidx = cidx_next - cidx;
   const bool invariant = zero <= s_cidx && s_cidx <= dim;
   if (cdim_name == CDimName::CRow) {
-    _assert(
+    __assert(
         invariant,
         "`0 <= crow_indices[..., 1:] - crow_indices[..., :-1] <= ncols` is not satisfied.");
   } else {
-    _assert(
+    __assert(
         invariant,
         "`0 <= ccol_indices[..., 1:] - ccol_indices[..., :-1] <= nrows` is not satisfied.");
   }
@@ -108,9 +108,9 @@ INVARIANT_CHECK_FUNC_API _check_idx_bounds(
     const index_t& dim) {
   const bool invariant = zero <= idx && idx < dim;
   if (cdim_name == CDimName::CRow) {
-    _assert(invariant, "`0 <= col_indices < ncols` is not satisfied.");
+    __assert(invariant, "`0 <= col_indices < ncols` is not satisfied.");
   } else {
-    _assert(invariant, "`0 <= row_indices < nrows` is not satisfied.");
+    __assert(invariant, "`0 <= row_indices < nrows` is not satisfied.");
   }
 }
 
@@ -129,14 +129,14 @@ INVARIANT_CHECK_FUNC_API _check_idx_sorted_distinct_va
   for (auto* RESTRICT curr = slice_begin + 1; curr < slice_end; ++curr) {
     const auto invariant = *(curr - 1) < *curr;
     if (cdim_name == CDimName::CRow) {
-      _assert(
+      __assert(
           invariant,
           "`col_indices[..., crow_indices[..., i - 1]:crow_indices[..., i]] "
           "for all i = 1, ..., nrows "
           "are sorted and distinct along the last dimension values` "
           "is not satisfied.");
     } else {
-      _assert(
+      __assert(
           invariant,
           "`row_indices[..., ccol_indices[..., i - 1]:ccol_indices[..., i]] "
           "for all i = 1, ..., ncols "
