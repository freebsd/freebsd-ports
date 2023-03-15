--- v8/include/v8config.h.orig	2023-03-15 07:46:50 UTC
+++ v8/include/v8config.h
@@ -183,6 +183,8 @@ path. Add it with -I<path> to the command line
   && !defined(V8_TARGET_OS_FUCHSIA) \
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
   && !defined(V8_TARGET_OS_MACOS) \
   && !defined(V8_TARGET_OS_WIN)
 #  error No known target OS defined.
@@ -194,6 +196,8 @@ path. Add it with -I<path> to the command line
   || defined(V8_TARGET_OS_FUCHSIA) \
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
   || defined(V8_TARGET_OS_MACOS) \
   || defined(V8_TARGET_OS_WIN)
 #  error A target OS is defined but V8_HAVE_TARGET_OS is unset.
@@ -216,6 +220,16 @@ path. Add it with -I<path> to the command line
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
@@ -351,10 +365,14 @@ path. Add it with -I<path> to the command line
 // - component builds fail because _dl_runtime_resolve clobbers registers,
 // - we see crashes on arm64 on Windows (https://crbug.com/1409934), which can
 //   hopefully be fixed in the future.
+// Additionally, the initial implementation in clang <= 16 overwrote the return
+// register(s) in the epilogue of a preserve_most function, so we only use
+// preserve_most in clang >= 17 (see https://reviews.llvm.org/D143425).
 #if (defined(_M_X64) || defined(__x86_64__)            /* x64 (everywhere) */  \
      || ((defined(__AARCH64EL__) || defined(_M_ARM64)) /* arm64, but ... */    \
          && !defined(_WIN32)))                         /* not on windows */    \
-     && !defined(COMPONENT_BUILD)                      /* no component build */
+     && !defined(COMPONENT_BUILD)                      /* no component build */\
+     && __clang_major__ >= 17                          /* clang >= 17 */
 # define V8_HAS_ATTRIBUTE_PRESERVE_MOST (__has_attribute(preserve_most))
 #endif
 # define V8_HAS_ATTRIBUTE_VISIBILITY (__has_attribute(visibility))
