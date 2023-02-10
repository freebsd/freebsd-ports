--- chrome/updater/ipc/ipc_names.h.orig	2023-02-08 09:03:45 UTC
+++ chrome/updater/ipc/ipc_names.h
@@ -13,7 +13,7 @@ namespace updater {
 mojo::NamedPlatformChannel::ServerName GetUpdateServiceInternalServerName(
     UpdaterScope scope);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 mojo::NamedPlatformChannel::ServerName GetUpdateServiceServerName(
     UpdaterScope scope);
 #endif  // BUILDFLAG(IS_LINUX)
