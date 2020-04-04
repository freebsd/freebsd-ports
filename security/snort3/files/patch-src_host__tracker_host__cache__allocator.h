--- src/host_tracker/host_cache_allocator.h.orig	2020-04-04 02:00:30 UTC
+++ src/host_tracker/host_cache_allocator.h
@@ -44,6 +44,22 @@ class HostCacheAlloc : public std::allocator<T> (prote
     HostCacheInterface* lru = 0;
 };
 
+template <class T>
+T* HostCacheAlloc<T>::allocate(std::size_t n)
+{
+    size_t sz = n * sizeof(T);
+    T* out = std::allocator<T>::allocate(n);
+    lru->update(sz);
+    return out;
+}
+
+template <class T>
+void HostCacheAlloc<T>::deallocate(T* p, std::size_t n) noexcept
+{
+    size_t sz = n * sizeof(T);
+    std::allocator<T>::deallocate(p, n);
+    lru->update(-(int) sz);
+}
 
 // Trivial derived allocator, pointing to their own host cache.
 // HostCacheAllocIp has a HostCacheInterface* pointing to an lru cache
