--- components/paint_preview/browser/paint_preview_client.cc.orig	2025-10-28 14:29:43 UTC
+++ components/paint_preview/browser/paint_preview_client.cc
@@ -478,8 +478,8 @@ void PaintPreviewClient::CapturePaintPreview(
   metadata->set_version(kPaintPreviewVersion);
   auto* chromeVersion = metadata->mutable_chrome_version();
   const auto& current_chrome_version = version_info::GetVersion();
-  chromeVersion->set_major(current_chrome_version.components()[0]);
-  chromeVersion->set_minor(current_chrome_version.components()[1]);
+  chromeVersion->set_gmajor(current_chrome_version.components()[0]);
+  chromeVersion->set_gminor(current_chrome_version.components()[1]);
   chromeVersion->set_build(current_chrome_version.components()[2]);
   chromeVersion->set_patch(current_chrome_version.components()[3]);
   document_data.callback = base::BindOnce(
