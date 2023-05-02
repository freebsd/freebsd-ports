--- remoting/base/mojo_util.cc.orig	2023-04-28 17:01:32 UTC
+++ remoting/base/mojo_util.cc
@@ -12,7 +12,7 @@ namespace remoting {
 
 void InitializeMojo(const mojo::core::Configuration& config) {
   mojo::core::Configuration new_config = config;
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // MojoIpcz has only been tested and verified on Linux. The Windows
   // multi-process architecture doesn't support MojoIpcz yet.
   new_config.disable_ipcz = true;
