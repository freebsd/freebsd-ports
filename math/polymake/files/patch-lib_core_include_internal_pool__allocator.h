--- lib/core/include/internal/pool_allocator.h.orig	2024-09-24 09:32:47 UTC
+++ lib/core/include/internal/pool_allocator.h
@@ -34,7 +34,11 @@ class allocator : public PM_ALLOCATOR_BASE<char> { (pu
 public:
    void* allocate(std::size_t n)
    {
+#if __cplusplus < 201703L
       return base_t::allocate(n, nullptr);
+#else
+      return base_t::allocate(n);
+#endif
    }
    void deallocate(void* p, std::size_t n)
    {
