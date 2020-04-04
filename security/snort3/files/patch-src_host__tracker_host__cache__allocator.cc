--- src/host_tracker/host_cache_allocator.cc.orig	2020-04-04 01:57:20 UTC
+++ src/host_tracker/host_cache_allocator.cc
@@ -24,23 +24,6 @@
 #include "host_cache.h"
 
 template <class T>
-T* HostCacheAlloc<T>::allocate(std::size_t n)
-{
-    size_t sz=n*sizeof(T);
-    T* out=std::allocator<T>::allocate(n);
-    lru->update(sz);
-    return out;
-}
-
-template <class T>
-void HostCacheAlloc<T>::deallocate(T* p, std::size_t n) noexcept
-{
-    size_t sz = n*sizeof(T);
-    std::allocator<T>::deallocate(p, n);
-    lru->update( -(int) sz);
-}
-
-template <class T>
 HostCacheAllocIp<T>::HostCacheAllocIp()
 {
     lru = &host_cache;
