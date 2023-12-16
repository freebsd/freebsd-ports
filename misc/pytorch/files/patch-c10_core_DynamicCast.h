- workaround for the failuree diring math/dgl build:
- /usr/local/lib/python3.9/site-packages/torch/include/c10/core/DynamicCast.h:112:22: error: use of undeclared identifier '__assert_fail'

--- c10/core/DynamicCast.h.orig	2023-05-10 02:37:18 UTC
+++ c10/core/DynamicCast.h
@@ -99,13 +99,13 @@ C10_HOST_DEVICE inline void cast_and_store(
   template <>                                                 \
   C10_HOST_DEVICE inline T fetch_and_cast<T>(                 \
       const ScalarType src_type, const void* ptr) {           \
-    CUDA_KERNEL_ASSERT(ScalarType::scalartype_ == src_type);  \
+    assert(ScalarType::scalartype_ == src_type);  \
     return c10::load<T>(ptr);                                 \
   }                                                           \
   template <>                                                 \
   C10_HOST_DEVICE inline void cast_and_store<T>(              \
       const ScalarType dest_type, void* ptr, T value) {       \
-    CUDA_KERNEL_ASSERT(ScalarType::scalartype_ == dest_type); \
+    assert(ScalarType::scalartype_ == dest_type); \
     *(T*)ptr = value;                                         \
   }
 
