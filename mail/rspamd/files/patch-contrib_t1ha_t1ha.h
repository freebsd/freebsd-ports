--- contrib/t1ha/t1ha.h.orig	2017-01-19 23:47:16 UTC
+++ contrib/t1ha/t1ha.h
@@ -42,6 +42,14 @@
 #define T1HA_INCLUDED
 #include "config.h"
 #include <string.h>
+#include <stddef.h>
+
+#ifndef __has_attribute
+#define __has_attribute(x) (0)
+#endif
+#ifndef __has_builtin
+#define __has_builtin(x) (0)
+#endif
 
 #ifdef BYTE_ORDER
 #ifndef __ORDER_LITTLE_ENDIAN__
@@ -88,9 +96,19 @@
 #endif
 #endif
 
-#if defined(__GNUC__) && (__GNUC__ > 3)
+#ifndef __GNUC_PREREQ
+#if defined(__GNUC__) && defined(__GNUC_MINOR__)
+#define __GNUC_PREREQ(maj, min)                                                \
+  ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
+#else
+#define __GNUC_PREREQ(maj, min) 0
+#endif
+#endif
 
-#if defined(__i386) || defined(__x86_64)
+
+#if __GNUC_PREREQ(4, 4) || defined(__clang__)
+
+#if defined(__i386__) || defined(__x86_64__)
 #include <x86intrin.h>
 #endif
 #define likely(cond) __builtin_expect(!!(cond), 1)
@@ -98,7 +116,12 @@
 #define unreachable() __builtin_unreachable()
 #define bswap64(v) __builtin_bswap64(v)
 #define bswap32(v) __builtin_bswap32(v)
+#if __GNUC_PREREQ(4, 8) || __has_builtin(__builtin_bswap16)
 #define bswap16(v) __builtin_bswap16(v)
+#endif
+#if __GNUC_PREREQ(4, 3) || __has_attribute(unused)
+#define maybe_unused __attribute__((unused))
+#endif
 
 #elif defined(_MSC_VER)
 
