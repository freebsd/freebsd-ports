--- gpu/config/gpu_util.cc.orig	2014-10-02 17:18:58 UTC
+++ gpu/config/gpu_util.cc
@@ -54,10 +54,12 @@
 }
 
 void ApplyGpuDriverBugWorkarounds(CommandLine* command_line) {
+#ifndef __FreeBSD__
   GPUInfo gpu_info;
   CollectBasicGraphicsInfo(&gpu_info);
 
   ApplyGpuDriverBugWorkarounds(gpu_info, command_line);
+#endif
 }
 
 void ApplyGpuDriverBugWorkarounds(
