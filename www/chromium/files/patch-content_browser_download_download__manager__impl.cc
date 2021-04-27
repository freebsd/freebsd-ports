--- content/browser/download/download_manager_impl.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/download/download_manager_impl.cc
@@ -83,7 +83,7 @@
 #include "third_party/blink/public/common/loader/referrer_utils.h"
 #include "third_party/blink/public/common/loader/throttling_url_loader.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -219,7 +219,7 @@ class DownloadItemFactoryImpl : public download::Downl
   }
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 base::FilePath GetTemporaryDownloadDirectory() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   return base::nix::GetXDGDirectory(env.get(), "XDG_DATA_HOME", ".local/share");
@@ -560,7 +560,7 @@ bool DownloadManagerImpl::InterceptDownload(
 
 base::FilePath DownloadManagerImpl::GetDefaultDownloadDirectory() {
   base::FilePath default_download_directory;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(thomasanderson,crbug.com/784010): Remove this when all Linux
   // distros with versions of GTK lower than 3.14.7 are no longer
   // supported.  This should happen when support for Ubuntu Trusty and
