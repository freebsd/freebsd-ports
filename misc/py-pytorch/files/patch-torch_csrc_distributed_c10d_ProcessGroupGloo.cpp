--- torch/csrc/distributed/c10d/ProcessGroupGloo.cpp.orig	2026-01-21 17:09:02 UTC
+++ torch/csrc/distributed/c10d/ProcessGroupGloo.cpp
@@ -32,6 +32,10 @@
 #include <gloo/rendezvous/context.h>
 #include <gloo/rendezvous/prefix_store.h>
 
+#if defined(__FreeBSD__)
+#define HOST_NAME_MAX 256
+#endif
+
 namespace c10d {
 
 namespace {
@@ -488,7 +492,7 @@ std::shared_ptr<::gloo::transport::Device> ProcessGrou
   return ::c10d::GlooDeviceFactory::makeDeviceForHostname(hostname, lazyInit);
 }
 
-#if defined(__linux__) || defined(_WIN32)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(_WIN32)
 std::shared_ptr<::gloo::transport::Device> ProcessGroupGloo::
     createDefaultDevice(bool lazyInit) {
   // Use the hostname to resolve the network address to
