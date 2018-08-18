--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2018-03-03 20:54:40.697792000 +0100
+++ content/gpu/gpu_sandbox_hook_linux.cc	2018-03-03 20:54:56.999743000 +0100
@@ -95,7 +95,7 @@
 #endif
 }
 
-constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL;
 
 void AddV4L2GpuWhitelist(
     std::vector<BrokerFilePermission>* permissions,
