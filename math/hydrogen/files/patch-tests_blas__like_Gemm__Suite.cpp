--- tests/blas_like/Gemm_Suite.cpp.orig	2023-11-08 23:05:42 UTC
+++ tests/blas_like/Gemm_Suite.cpp
@@ -555,11 +555,11 @@ struct HalfTypeT<Device::GPU>
     using type = gpu_half_type;
 };
 #else
-template <>
-struct HalfTypeT<Device::GPU>
-{
-    using type = UndefinedType;
-};
+//template <>
+//struct HalfTypeT<Device::GPU>
+//{
+//    using type = UndefinedType;
+//};
 #endif // HYDROGEN_HAVE_GPU
 #endif // HYDROGEN_HAVE_HALF
 
