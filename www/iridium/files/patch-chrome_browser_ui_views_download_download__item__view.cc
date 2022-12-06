--- chrome/browser/ui/views/download/download_item_view.cc.orig	2022-12-06 08:09:13 UTC
+++ chrome/browser/ui/views/download/download_item_view.cc
@@ -190,7 +190,7 @@ bool UseNewWarnings() {
 }
 
 int GetFilenameStyle(const views::Label& label) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   if (UseNewWarnings())
     return views::style::STYLE_EMPHASIZED;
 #endif
@@ -198,7 +198,7 @@ int GetFilenameStyle(const views::Label& label) {
 }
 
 int GetFilenameStyle(const views::StyledLabel& label) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   if (UseNewWarnings())
     return views::style::STYLE_EMPHASIZED;
 #endif
