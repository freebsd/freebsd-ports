--- src/core/runtime/amd_loader_context.cpp.orig	2018-11-19 02:58:50 UTC
+++ src/core/runtime/amd_loader_context.cpp
@@ -207,7 +207,7 @@ bool MappedMemory::Allocate(size_t size, size_t align,
 #else
   ptr_ = is_kv_ ?
     mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0) :
-    mmap(nullptr, size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE, -1, 0);
+    mmap(nullptr, size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
 #endif // _WIN32 || _WIN64
   if (nullptr == ptr_) {
     return false;
