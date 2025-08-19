--- torch/csrc/distributed/c10d/ProcessGroupGloo.cpp.orig	2025-06-04 18:15:57 UTC
+++ torch/csrc/distributed/c10d/ProcessGroupGloo.cpp
@@ -111,6 +111,10 @@
   }
 #endif
 
+#if defined(__FreeBSD__)
+#define HOST_NAME_MAX 256
+#endif
+
 namespace c10d {
 
 namespace {
@@ -705,7 +709,7 @@ std::shared_ptr<::gloo::transport::Device> ProcessGrou
   return ::c10d::GlooDeviceFactory::makeDeviceForHostname(hostname);
 }
 
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(_WIN32)
 std::shared_ptr<::gloo::transport::Device> ProcessGroupGloo::
     createDefaultDevice() {
   // Use the hostname to resolve the network address to
