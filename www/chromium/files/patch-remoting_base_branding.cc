--- remoting/base/branding.cc.orig	2026-10-18 13:29:39 UTC
+++ remoting/base/branding.cc
@@ -11,7 +11,7 @@
 #include "build/branding_buildflags.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <unistd.h>
 
 #include "remoting/base/file_path_util_linux.h"
@@ -35,12 +35,12 @@ const base::FilePath::CharType kConfigDir[] = FILE_PAT
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
@@ -74,7 +74,7 @@ const wchar_t kHostUpdatePendingEventName[] =
 #endif  // BUILDFLAG(IS_WIN)
 
 base::FilePath GetConfigDir() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (getuid() == /*root*/ 0 || GetUsername() == GetNetworkProcessUsername()) {
     // Processes run as root:
     //     daemon process,
