--- src/common/mm_mem_io_p.h.orig	2019-01-05 15:10:16 UTC
+++ src/common/mm_mem_io_p.h
@@ -28,8 +28,8 @@ class mm_mem_io_private_c : public mm_io_private_c { (
   explicit mm_mem_io_private_c(unsigned char *p_mem,
                                uint64_t p_mem_size,
                                std::size_t p_increase)
-    : mem_size{p_mem_size}
-    , allocated{p_mem_size}
+    : mem_size{static_cast<size_t>(p_mem_size)}
+    , allocated{static_cast<size_t>(p_mem_size)}
     , increase{p_increase}
     , mem{p_mem}
   {
@@ -48,8 +48,8 @@ class mm_mem_io_private_c : public mm_io_private_c { (
 
   explicit mm_mem_io_private_c(unsigned char const *p_mem,
                                uint64_t p_mem_size)
-    : mem_size{p_mem_size}
-    , allocated{p_mem_size}
+    : mem_size{static_cast<size_t>(p_mem_size)}
+    , allocated{static_cast<size_t>(p_mem_size)}
     , ro_mem{p_mem}
     , read_only{true}
   {
