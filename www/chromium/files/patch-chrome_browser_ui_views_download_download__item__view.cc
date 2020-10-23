--- chrome/browser/ui/views/download/download_item_view.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/browser/ui/views/download/download_item_view.cc
@@ -207,7 +207,7 @@ class TransparentButton : public views::Button {
 };
 
 int GetFilenameStyle(const views::StyledLabel& label) {
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(safe_browsing::kUseNewDownloadWarnings))
     return STYLE_EMPHASIZED;
 #endif
@@ -276,7 +276,7 @@ DownloadItemView::DownloadItemView(DownloadUIModel::Do
   open_button_ = AddChildView(std::move(open_button));
 
   int file_name_style = views::style::STYLE_PRIMARY;
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(safe_browsing::kUseNewDownloadWarnings))
     file_name_style = STYLE_EMPHASIZED;
 #endif
