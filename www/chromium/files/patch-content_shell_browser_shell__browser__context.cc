--- content/shell/browser/shell_browser_context.cc.orig	2017-06-05 19:03:07 UTC
+++ content/shell/browser/shell_browser_context.cc
@@ -25,7 +25,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
@@ -101,7 +101,7 @@ void ShellBrowserContext::InitWhileIOAllowed() {
 #if defined(OS_WIN)
   CHECK(PathService::Get(base::DIR_LOCAL_APP_DATA, &path_));
   path_ = path_.Append(std::wstring(L"content_shell"));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(
       base::nix::GetXDGDirectory(env.get(),
