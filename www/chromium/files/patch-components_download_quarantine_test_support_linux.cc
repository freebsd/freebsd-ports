--- components/download/quarantine/test_support_linux.cc.orig	2018-12-13 19:01:53.437126000 +0100
+++ components/download/quarantine/test_support_linux.cc	2018-12-13 19:02:49.728978000 +0100
@@ -22,6 +22,7 @@
 
 std::string GetExtendedFileAttribute(const char* path, const char* name) {
   base::AssertBlockingAllowed();
+#if !defined(OS_BSD)
   ssize_t len = getxattr(path, name, nullptr, 0);
   if (len <= 0)
     return std::string();
@@ -31,6 +32,9 @@
   if (len < static_cast<ssize_t>(buffer.size()))
     return std::string();
   return std::string(buffer.begin(), buffer.end());
+#else
+  return std::string();
+#endif // !defined(OS_BSD)
 }
 
 }  // namespace
