--- v8/include/v8config.h.orig	2022-02-07 13:39:41 UTC
+++ v8/include/v8config.h
@@ -181,6 +181,8 @@ path. Add it with -I<path> to the command line
   && !defined(V8_TARGET_OS_FUCHSIA) \
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
   && !defined(V8_TARGET_OS_MACOSX) \
   && !defined(V8_TARGET_OS_WIN)
 #  error No known target OS defined.
@@ -192,6 +194,8 @@ path. Add it with -I<path> to the command line
   || defined(V8_TARGET_OS_FUCHSIA) \
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
   || defined(V8_TARGET_OS_MACOSX) \
   || defined(V8_TARGET_OS_WIN)
 #  error A target OS is defined but V8_HAVE_TARGET_OS is unset.
@@ -212,6 +216,16 @@ path. Add it with -I<path> to the command line
 
 #ifdef V8_OS_LINUX
 # define V8_TARGET_OS_LINUX
+#endif
+
+#ifdef V8_OS_OPENBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
+#ifdef V8_OS_FREEBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
 #endif
 
 #ifdef V8_OS_MACOSX
