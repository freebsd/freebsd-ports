--- ./base/strings/safe_sprintf.cc.orig	2014-04-30 22:41:43.000000000 +0200
+++ ./base/strings/safe_sprintf.cc	2014-05-04 14:38:46.000000000 +0200
@@ -107,11 +107,11 @@
       : buffer_(buffer),
         size_(size - 1),  // Account for trailing NUL byte
         count_(0) {
-// The following assertion does not build on Mac and Android. This is because
-// static_assert only works with compile-time constants, but mac uses
-// libstdc++4.2 and android uses stlport, which both don't mark
-// numeric_limits::max() as constexp.
-#if __cplusplus >= 201103 && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_IOS)
+// The following assertion does not build on Mac and Android and older FreeBSD.
+// This is because static_assert only works with compile-time constants, but
+// mac and FreeBSD < 10 use libstdc++4.2 and android uses stlport, which both
+// don't mark numeric_limits::max() as constexp.
+#if __cplusplus >= 201103 && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_IOS) && !(defined(OS_FREEBSD) && __FreeBSD_version > 1000054)
     COMPILE_ASSERT(kSSizeMaxConst == \
                    static_cast<size_t>(std::numeric_limits<ssize_t>::max()),
                    kSSizeMax_is_the_max_value_of_an_ssize_t);
