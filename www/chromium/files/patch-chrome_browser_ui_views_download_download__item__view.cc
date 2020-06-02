--- chrome/browser/ui/views/download/download_item_view.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/browser/ui/views/download/download_item_view.cc
@@ -234,7 +234,7 @@ DownloadItemView::DownloadItemView(DownloadUIModel::Do
   open_button_ = AddChildView(std::move(open_button));
 
   int file_name_style = views::style::STYLE_PRIMARY;
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(safe_browsing::kUseNewDownloadWarnings))
     file_name_style = STYLE_EMPHASIZED;
 #endif
@@ -1635,7 +1635,7 @@ void DownloadItemView::StyleFilenameInLabel(views::Sty
   if (!base::FeatureList::IsEnabled(safe_browsing::kUseNewDownloadWarnings))
     return;
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   base::string16 filename = ElidedFilename();
   size_t file_name_position = label->GetText().find(filename);
   if (file_name_position != std::string::npos) {
