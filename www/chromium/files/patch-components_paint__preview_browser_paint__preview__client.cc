--- components/paint_preview/browser/paint_preview_client.cc.orig	2021-04-27 10:13:50 UTC
+++ components/paint_preview/browser/paint_preview_client.cc
@@ -302,8 +302,8 @@ void PaintPreviewClient::CapturePaintPreview(
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
