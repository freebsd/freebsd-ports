--- components/download/quarantine/test_support_linux.cc.orig	2019-01-30 02:17:53.000000000 +0100
+++ components/download/quarantine/test_support_linux.cc	2019-01-31 23:56:27.334442000 +0100
@@ -21,6 +21,7 @@
 namespace {
 
 std::string GetExtendedFileAttribute(const char* path, const char* name) {
+#if !defined(OS_BSD)
   base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::MAY_BLOCK);
   ssize_t len = getxattr(path, name, nullptr, 0);
   if (len <= 0)
@@ -31,6 +32,9 @@
   if (len < static_cast<ssize_t>(buffer.size()))
     return std::string();
   return std::string(buffer.begin(), buffer.end());
+#else
+  return std::string();
+#endif // !defined(OS_BSD)
 }
 
 }  // namespace
