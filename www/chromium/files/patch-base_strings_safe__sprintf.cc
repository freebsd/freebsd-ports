--- base/strings/safe_sprintf.cc.orig	2016-03-25 13:04:44 UTC
+++ base/strings/safe_sprintf.cc
@@ -115,8 +115,11 @@ class Buffer {
         count_(0) {
 // MSVS2013's standard library doesn't mark max() as constexpr yet. cl.exe
 // supports static_cast but doesn't really implement constexpr yet so it doesn't
-// complain, but clang does.
-#if __cplusplus >= 201103 && !(defined(__clang__) && defined(OS_WIN))
+// complain, but clang does. Older FreeBSD (<10) use libstdc++4.2, which
+// doesn't mark numeric_limits::max() as constexp.
+#if __cplusplus >= 201103 && \
+	!(defined(OS_FREEBSD) && __FreeBSD_version > 1000054) && \
+	!(defined(__clang__) && defined(OS_WIN))
     static_assert(kSSizeMaxConst ==
                       static_cast<size_t>(std::numeric_limits<ssize_t>::max()),
                   "kSSizeMaxConst should be the max value of an ssize_t");
