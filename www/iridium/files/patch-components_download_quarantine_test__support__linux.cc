--- components/download/quarantine/test_support_linux.cc.orig	2019-03-11 22:00:56 UTC
+++ components/download/quarantine/test_support_linux.cc
@@ -21,6 +21,7 @@ namespace download {
 namespace {
 
 std::string GetExtendedFileAttribute(const char* path, const char* name) {
+#if !defined(OS_BSD)
   base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::MAY_BLOCK);
   ssize_t len = getxattr(path, name, nullptr, 0);
   if (len <= 0)
@@ -31,6 +32,9 @@ std::string GetExtendedFileAttribute(const char* path,
   if (len < static_cast<ssize_t>(buffer.size()))
     return std::string();
   return std::string(buffer.begin(), buffer.end());
+#else
+  return std::string();
+#endif // !defined(OS_BSD)
 }
 
 }  // namespace
