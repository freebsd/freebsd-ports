--- chrome/browser/ui/views/download_item_view.cc.orig	2011-04-15 11:01:46.000000000 +0300
+++ chrome/browser/ui/views/download_item_view.cc	2011-04-15 22:56:06.858645022 +0300
@@ -261,7 +261,7 @@
 
     // Extract the file extension (if any).
     FilePath filename(download->target_name());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     string16 extension = WideToUTF16(base::SysNativeMBToWide(
         filename.Extension()));
 #else
@@ -271,7 +271,7 @@
     // Remove leading '.'
     if (extension.length() > 0)
       extension = extension.substr(1);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     string16 rootname = WideToUTF16(base::SysNativeMBToWide(
         filename.RemoveExtension().value()));
 #else
