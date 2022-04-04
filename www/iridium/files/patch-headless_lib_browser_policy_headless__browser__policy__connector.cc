--- headless/lib/browser/policy/headless_browser_policy_connector.cc.orig	2022-04-03 12:23:22 UTC
+++ headless/lib/browser/policy/headless_browser_policy_connector.cc
@@ -148,8 +148,10 @@ HeadlessBrowserPolicyConnector::CreatePlatformProvider
   // chrome/common/chrome_paths.cc
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   base::FilePath config_dir_path(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif BUILDFLAG(IS_FREEBSD)
+  base::FilePath config_dir_path(FILE_PATH_LITERAL("/usr/local/etc/iridium/policies"));
 #else
-  base::FilePath config_dir_path(FILE_PATH_LITERAL("/etc/iridium-browser/policies"));
+  base::FilePath config_dir_path(FILE_PATH_LITERAL("/etc/iridium/policies"));
 #endif
   std::unique_ptr<AsyncPolicyLoader> loader(new ConfigDirPolicyLoader(
       base::ThreadPool::CreateSequencedTaskRunner(
