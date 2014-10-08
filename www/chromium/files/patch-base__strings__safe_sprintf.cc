--- base/strings/safe_sprintf.cc.orig	2014-10-02 17:18:52 UTC
+++ base/strings/safe_sprintf.cc
@@ -107,15 +107,16 @@
       : buffer_(buffer),
         size_(size - 1),  // Account for trailing NUL byte
         count_(0) {
-// The following assertion does not build on Mac and Android. This is because
-// static_assert only works with compile-time constants, but mac uses
-// libstdc++4.2 and android uses stlport, which both don't mark
-// numeric_limits::max() as constexp.  Likewise, MSVS2013's standard library
-// also doesn't mark max() as constexpr yet. cl.exe supports static_cast but
-// doesn't really implement constexpr yet so it doesn't complain, but clang
+// The following assertion does not build on Mac and Android and older FreeBSD.
+// This is because static_assert only works with compile-time constants, but
+// mac and FreeBSD < 10 use libstdc++4.2 and android uses stlport, which both
+// don't mark numeric_limits::max() as constexp.  Likewise, MSVS2013's standard
+// library also doesn't mark max() as constexpr yet. cl.exe supports static_cast
+// but doesn't really implement constexpr yet so it doesn't complain, but clang
 // does.
 #if __cplusplus >= 201103 && !defined(OS_ANDROID) && !defined(OS_MACOSX) && \
-    !defined(OS_IOS) && !(defined(__clang__) && defined(OS_WIN))
+    !defined(OS_IOS) && !(defined(OS_FREEBSD) && __FreeBSD_version > 1000054) \
+    && !(defined(__clang__) && defined(OS_WIN))
     COMPILE_ASSERT(kSSizeMaxConst == \
                    static_cast<size_t>(std::numeric_limits<ssize_t>::max()),
                    kSSizeMax_is_the_max_value_of_an_ssize_t);
