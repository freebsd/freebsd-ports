--- ../ref/blake2.h.orig	2015-06-01 01:10:19 UTC
+++ ../ref/blake2.h
@@ -19,6 +19,8 @@
 
 #if defined(_MSC_VER)
 #define ALIGN(x) __declspec(align(x))
+#elif defined(__clang__)
+#define ALIGN(x) /* unaligned access in b2*p at -O >0 */
 #else
 #define ALIGN(x) __attribute__((aligned(x)))
 #endif
--- ../sse/blake2.h.orig	2015-05-29 08:02:54 UTC
+++ ../sse/blake2.h
@@ -19,6 +19,8 @@
 
 #if defined(_MSC_VER)
 #define ALIGN(x) __declspec(align(x))
+#elif defined(__clang__)
+#define ALIGN(x) /* unaligned access in b2*p at -O >0 */
 #else
 #define ALIGN(x) __attribute__ ((__aligned__(x)))
 #endif
