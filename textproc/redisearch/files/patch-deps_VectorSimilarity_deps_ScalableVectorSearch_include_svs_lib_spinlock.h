--- deps/VectorSimilarity/deps/ScalableVectorSearch/include/svs/lib/spinlock.h.orig	2026-05-30 14:27:46 UTC
+++ deps/VectorSimilarity/deps/ScalableVectorSearch/include/svs/lib/spinlock.h
@@ -24,6 +24,8 @@
 inline void pause() {
 #if defined(__i386__) || defined(__x86_64__)
     __builtin_ia32_pause();
+#elif defined(__powerpc__) || defined(__powerpc64__)
+    asm volatile("or 27,27,27" ::: "memory");
 #else //  __aarch64__
     asm volatile("yield" ::: "memory");
 #endif
