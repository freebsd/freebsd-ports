--- remoting/base/branding.cc.orig	2026-04-15 12:07:04 UTC
+++ remoting/base/branding.cc
@@ -10,7 +10,7 @@
 #include "base/path_service.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <unistd.h>
 
 #include "remoting/base/file_path_util_linux.h"
@@ -34,12 +34,12 @@ const base::FilePath::CharType kConfigDir[] = FILE_PAT
 #elif BUILDFLAG(IS_APPLE)
 const base::FilePath::CharType kConfigDir[] =
     FILE_PATH_LITERAL("Chrome Remote Desktop");
-#elif !BUILDFLAG(IS_LINUX)
+#elif !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kConfigDir[] =
     FILE_PATH_LITERAL(".config/chrome-remote-desktop");
 #endif
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 base::FilePath GetConfigDirWithPrefix(int prefix_path_key) {
   base::FilePath app_data_dir;
   base::PathService::Get(prefix_path_key, &app_data_dir);
@@ -60,7 +60,7 @@ const wchar_t kWindowsServiceName[] = L"chromoting";
 #endif
 
 base::FilePath GetConfigDir() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (getuid() == /*root*/ 0 || GetUsername() == GetNetworkProcessUsername()) {
     // Processes run as root:
     //     daemon process,
