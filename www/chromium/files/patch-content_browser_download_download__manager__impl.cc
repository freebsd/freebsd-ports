--- content/browser/download/download_manager_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ content/browser/download/download_manager_impl.cc
@@ -89,7 +89,7 @@
 #include "third_party/blink/public/common/storage_key/storage_key.h"
 #include "url/origin.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/nix/xdg_util.h"
 #endif
 
@@ -236,7 +236,7 @@ class DownloadItemFactoryImpl : public download::Downl
   }
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 base::FilePath GetTemporaryDownloadDirectory() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   return base::nix::GetXDGDirectory(env.get(), "XDG_DATA_HOME", ".local/share");
@@ -592,7 +592,7 @@ bool DownloadManagerImpl::InterceptDownload(
 
 base::FilePath DownloadManagerImpl::GetDefaultDownloadDirectory() {
   base::FilePath default_download_directory;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(thomasanderson,crbug.com/784010): Remove this when all Linux
   // distros with versions of GTK lower than 3.14.7 are no longer
   // supported.  This should happen when support for Ubuntu Trusty and
