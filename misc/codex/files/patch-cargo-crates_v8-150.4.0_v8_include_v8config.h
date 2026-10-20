--- cargo-crates/v8-150.4.0/v8/include/v8config.h.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/include/v8config.h
@@ -207,6 +207,8 @@
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_TVOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
   && !defined(V8_TARGET_OS_MACOS) \
   && !defined(V8_TARGET_OS_WIN) \
   && !defined(V8_TARGET_OS_CHROMEOS)
@@ -220,6 +222,8 @@
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_TVOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
   || defined(V8_TARGET_OS_MACOS) \
   || defined(V8_TARGET_OS_WIN) \
   || defined(V8_TARGET_OS_CHROMEOS)
@@ -247,6 +251,16 @@
 # define V8_TARGET_OS_LINUX
 #endif
 
+#ifdef V8_OS_OPENBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
+#ifdef V8_OS_FREEBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
 #ifdef V8_OS_MACOS
 # define V8_TARGET_OS_MACOS
 #endif
@@ -394,6 +408,7 @@
 #if (defined(_M_X64) || defined(__x86_64__)            /* x64 (everywhere) */  \
      || ((defined(__AARCH64EL__) || defined(_M_ARM64)) /* arm64, but ... */    \
          && !defined(_WIN32)))                         /* not on windows */    \
+     && !defined(__OpenBSD__)                          /* not on OpenBSD */    \
      && !defined(COMPONENT_BUILD)                      /* no component build */\
      && __clang_major__ >= 17                          /* clang >= 17 */
 # define V8_HAS_ATTRIBUTE_PRESERVE_MOST (__has_attribute(preserve_most))
@@ -1028,7 +1043,7 @@
 #define V8_TARGET_LITTLE_ENDIAN 1
 #endif
 #elif V8_TARGET_ARCH_PPC64
-#if V8_OS_AIX
+#if defined(__BIG_ENDIAN__) || defined(V8_OS_AIX)
 #define V8_TARGET_BIG_ENDIAN 1
 #else
 #define V8_TARGET_LITTLE_ENDIAN 1
