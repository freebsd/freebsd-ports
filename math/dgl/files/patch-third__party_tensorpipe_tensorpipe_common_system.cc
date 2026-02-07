--- third_party/tensorpipe/tensorpipe/common/system.cc.orig	2021-08-31 10:11:56 UTC
+++ third_party/tensorpipe/tensorpipe/common/system.cc
@@ -16,6 +16,13 @@
 #include <unistd.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <pthread.h>
+#include <sys/stat.h>
+#include <sys/types.h>
+#include <unistd.h>
+#endif
+
 #ifdef __APPLE__
 #include <IOKit/IOKitLib.h>
 #endif
@@ -141,8 +148,9 @@ std::string removeBlankSpaces(std::string s) {
 }
 
 optional<std::string> getBootID() {
-  static optional<std::string> bootID = getBootIDInternal();
-  return bootID;
+  //static optional<std::string> bootID = getBootIDInternal();
+  //return bootID;
+  throw std::runtime_error("tensorpipe lacks FreeBSD support (getBootIDInternal), see https://github.com/pytorch/tensorpipe/issues/461");
 }
 
 #ifdef __APPLE__
@@ -277,6 +285,12 @@ optional<std::string> getPermittedCapabilitiesID() {
   std::ostringstream oss;
   oss << std::hex << bitmask;
   return oss.str();
+}
+
+#elif defined(__FreeBSD__)
+
+optional<std::string> getLinuxNamespaceId(LinuxNamespace ns) {
+  return std::string();
 }
 
 #endif
