--- src/LDHT/Util.h.orig	2012-03-30 10:53:05 UTC
+++ src/LDHT/Util.h
@@ -10,6 +10,10 @@
 #include <cstdlib>
 #include <cstring>
 #include <stdint.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #define V(expr) std::cerr << __FILE__ << ":" \
                           << __LINE__ << " " \
@@ -43,6 +47,9 @@ class Util { (public)
     static uint64_t hash(uint64_t a, uint64_t b, uint64_t P, uint8_t* e);
     static uint64_t hash(uint64_t a, uint64_t b, uint64_t P, uint64_t e);
     static inline uint64_t rdtsc() {
+#if defined(__powerpc__)
+        return __builtin_readcyclecounter();
+#else
         uint32_t lo, hi;
         __asm__ __volatile__(
                 "xorl %%eax,%%eax\n"
@@ -52,6 +59,7 @@ class Util { (public)
                 :
                 : "%ebx", "%ecx");
         return static_cast<uint64_t>(hi) << 32 | lo;
+#endif
     };
 };
 
