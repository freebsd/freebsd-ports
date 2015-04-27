--- gpu/config/gpu_util.cc.orig	2015-04-19 16:27:01.000000000 +0200
+++ gpu/config/gpu_util.cc	2015-04-19 16:27:30.000000000 +0200
@@ -54,10 +54,12 @@
 }
 
 void ApplyGpuDriverBugWorkarounds(base::CommandLine* command_line) {
+#ifndef __FreeBSD__
   GPUInfo gpu_info;
   CollectBasicGraphicsInfo(&gpu_info);
 
   ApplyGpuDriverBugWorkarounds(gpu_info, command_line);
+#endif
 }
 
 void ApplyGpuDriverBugWorkarounds(const GPUInfo& gpu_info,
