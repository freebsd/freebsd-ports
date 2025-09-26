--- cargo-crates/v8-137.2.1/v8/include/v8config.h.orig	2020-06-26 16:28:04 UTC
+++ cargo-crates/v8-137.2.1/v8/include/v8config.h
@@ -202,6 +202,7 @@ path. Add it with -I<path> to the command line
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_LINUX) \
   && !defined(V8_TARGET_OS_MACOS) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
   && !defined(V8_TARGET_OS_WIN) \
   && !defined(V8_TARGET_OS_CHROMEOS)
 #  error No known target OS defined.
@@ -214,6 +215,7 @@ path. Add it with -I<path> to the command line
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_LINUX) \
   || defined(V8_TARGET_OS_MACOS) \
+  || defined(V8_TARGET_OS_FREEBSD) \
   || defined(V8_TARGET_OS_WIN) \
   || defined(V8_TARGET_OS_CHROMEOS)
 #  error A target OS is defined but V8_HAVE_TARGET_OS is unset.
@@ -236,6 +238,11 @@ path. Add it with -I<path> to the command line
 # define V8_TARGET_OS_LINUX
 #endif
 
+#ifdef V8_OS_FREEBSD
+# define V8_TARGET_OS_FREEBSD
+# define V8_TARGET_OS_BSD
+#endif
+
 #ifdef V8_OS_MACOS
 # define V8_TARGET_OS_MACOS
 #endif
@@ -382,6 +389,7 @@ path. Add it with -I<path> to the command line
 #if (defined(_M_X64) || defined(__x86_64__)            /* x64 (everywhere) */  \
      || ((defined(__AARCH64EL__) || defined(_M_ARM64)) /* arm64, but ... */    \
          && !defined(_WIN32)))                         /* not on windows */    \
+     && !defined(__FreeBSD__)                          /* not on FreeBSD */    \
      && !defined(COMPONENT_BUILD)                      /* no component build */\
      && __clang_major__ >= 17                          /* clang >= 17 */
 # define V8_HAS_ATTRIBUTE_PRESERVE_MOST (__has_attribute(preserve_most))
