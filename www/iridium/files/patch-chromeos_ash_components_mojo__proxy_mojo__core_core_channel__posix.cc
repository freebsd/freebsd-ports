--- chromeos/ash/components/mojo_proxy/mojo_core/core/channel_posix.cc.orig	2026-08-13 16:48:13 UTC
+++ chromeos/ash/components/mojo_proxy/mojo_core/core/channel_posix.cc
@@ -30,7 +30,7 @@
 #include "build/build_config.h"
 #include "chromeos/ash/components/mojo_proxy/mojo_core/public/cpp/platform/socket_utils_posix.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 #include "chromeos/ash/components/mojo_proxy/mojo_core/core/channel_linux.h"
 #endif
 
@@ -600,7 +600,7 @@ scoped_refptr<Channel> Channel::Create(
     ConnectionParams connection_params,
     HandlePolicy handle_policy,
     scoped_refptr<base::SingleThreadTaskRunner> io_task_runner) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return new ChannelLinux(delegate, std::move(connection_params), handle_policy,
                           io_task_runner);
 #else
@@ -609,7 +609,7 @@ scoped_refptr<Channel> Channel::Create(
 #endif
 }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 // static
 bool Channel::SupportsChannelUpgrade() {
   return ChannelLinux::KernelSupportsUpgradeRequirements() &&
