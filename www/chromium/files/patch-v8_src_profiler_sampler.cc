--- v8/src/profiler/sampler.cc.orig	2016-08-04 11:28:06.738852000 -0400
+++ v8/src/profiler/sampler.cc	2016-08-04 11:28:29.356607000 -0400
@@ -210,7 +210,7 @@
 
 // Returns hash value for hash map.
 uint32_t ThreadHash(pthread_t thread_id) {
-#if V8_OS_MACOSX
+#if defined(V8_OS_MACOSX) || defined(__OpenBSD__) || defined(__FreeBSD__)
   return static_cast<uint32_t>(reinterpret_cast<intptr_t>(thread_id));
 #else
   return static_cast<uint32_t>(thread_id);
