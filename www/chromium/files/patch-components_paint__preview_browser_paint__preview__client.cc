--- components/paint_preview/browser/paint_preview_client.cc.orig	2022-02-07 13:39:41 UTC
+++ components/paint_preview/browser/paint_preview_client.cc
@@ -313,8 +313,8 @@ void PaintPreviewClient::CapturePaintPreview(
   metadata->set_url(url.spec());
   metadata->set_version(kPaintPreviewVersion);
   auto* chromeVersion = metadata->mutable_chrome_version();
-  chromeVersion->set_major(CHROME_VERSION_MAJOR);
-  chromeVersion->set_minor(CHROME_VERSION_MINOR);
+  chromeVersion->set_gmajor(CHROME_VERSION_MAJOR);
+  chromeVersion->set_gminor(CHROME_VERSION_MINOR);
   chromeVersion->set_build(CHROME_VERSION_BUILD);
   chromeVersion->set_patch(CHROME_VERSION_PATCH);
   document_data.callback = std::move(callback);
