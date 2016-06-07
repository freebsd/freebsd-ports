--- content/shell/browser/shell_browser_context.cc.orig	2016-05-11 19:02:22 UTC
+++ content/shell/browser/shell_browser_context.cc
@@ -24,7 +24,7 @@
 
 #if defined(OS_WIN)
 #include "base/base_paths_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #elif defined(OS_MACOSX)
 #include "base/base_paths_mac.h"
@@ -79,7 +79,7 @@ void ShellBrowserContext::InitWhileIOAll
 #if defined(OS_WIN)
   CHECK(PathService::Get(base::DIR_LOCAL_APP_DATA, &path_));
   path_ = path_.Append(std::wstring(L"content_shell"));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   scoped_ptr<base::Environment> env(base::Environment::Create());
   base::FilePath config_dir(
       base::nix::GetXDGDirectory(env.get(),
