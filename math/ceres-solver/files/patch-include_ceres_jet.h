https://github.com/ceres-solver/ceres-solver/issues/235

--- include/ceres/jet.h.orig	2016-10-13 16:52:02 UTC
+++ include/ceres/jet.h
@@ -242,7 +242,7 @@ struct Jet {
       16 <= ::ceres::port_constants::kMaxAlignBytes;
   static constexpr int kAlignHint = kShouldAlignMatrix ?
       Eigen::AutoAlign : Eigen::DontAlign;
-  static constexpr size_t kAlignment = kShouldAlignMatrix ? 16 : 1;
+  static constexpr size_t kAlignment = kShouldAlignMatrix ? 16 : 4;
   alignas(kAlignment) Eigen::Matrix<T, N, 1, kAlignHint> v;
 #endif
 };
