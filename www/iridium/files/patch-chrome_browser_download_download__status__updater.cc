--- chrome/browser/download/download_status_updater.cc.orig	2018-06-13 00:10:05.000000000 +0200
+++ chrome/browser/download/download_status_updater.cc	2018-07-15 13:07:15.012034000 +0200
@@ -13,7 +13,7 @@
 #include "base/memory/ptr_util.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "ui/views/linux_ui/linux_ui.h"
 #endif
 
@@ -136,7 +136,7 @@
 #if defined(OS_ANDROID) || (defined(USE_AURA) && !defined(OS_WIN))
 void DownloadStatusUpdater::UpdateAppIconDownloadProgress(
     download::DownloadItem* download) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   const views::LinuxUI* linux_ui = views::LinuxUI::instance();
   if (linux_ui) {
     float progress = 0;
