-- Add 'static' to get_random_seed() to prevent multiple definition errors
-- when the header is included in multiple translation units.
--- third_party/eigen3/unsupported/Eigen/CXX11/src/Tensor/TensorRandom.h.orig	2021-03-15 20:32:24 UTC
+++ third_party/eigen3/unsupported/Eigen/CXX11/src/Tensor/TensorRandom.h
@@ -16,7 +16,7 @@ namespace {
 
 namespace {
 
-EIGEN_DEVICE_FUNC uint64_t get_random_seed() {
+static EIGEN_DEVICE_FUNC uint64_t get_random_seed() {
 #if defined(EIGEN_GPU_COMPILE_PHASE)
   // We don't support 3d kernels since we currently only use 1 and
   // 2d kernels.
