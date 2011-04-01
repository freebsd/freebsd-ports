--- ./chrome/browser/ui/views/download_item_view.cc.orig	2010-12-16 02:11:56.000000000 +0100
+++ ./chrome/browser/ui/views/download_item_view.cc	2010-12-20 20:15:08.000000000 +0100
@@ -259,7 +259,7 @@
 
     // Extract the file extension (if any).
     FilePath filename(download->target_name());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     std::wstring extension = base::SysNativeMBToWide(filename.Extension());
 #else
     std::wstring extension = filename.Extension();
@@ -268,7 +268,7 @@
     // Remove leading '.'
     if (extension.length() > 0)
       extension = extension.substr(1);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     std::wstring rootname =
         base::SysNativeMBToWide(filename.RemoveExtension().value());
 #else
