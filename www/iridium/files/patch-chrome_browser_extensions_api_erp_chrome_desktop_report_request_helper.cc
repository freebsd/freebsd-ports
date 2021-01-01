--- chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc.orig	2020-04-03 04:11:29 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc
@@ -39,7 +39,7 @@
 #include "base/win/registry.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -382,7 +382,7 @@ base::FilePath GetEndpointVerificationDir() {
     return *GetEndpointVerificationDirOverride();
 #if defined(OS_WIN)
   if (!base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path))
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   path = base::nix::GetXDGDirectory(env.get(), base::nix::kXdgConfigHomeEnvVar,
                                     base::nix::kDotConfigDir);
@@ -393,7 +393,7 @@ base::FilePath GetEndpointVerificationDir() {
   if (true)
 #endif
     return path;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   path = path.AppendASCII("google");
 #else
   path = path.AppendASCII("Google");
