--- chrome/browser/ui/webui/certificate_viewer_webui.cc.orig	2014-01-07 21:01:49.000000000 +0100
+++ chrome/browser/ui/webui/certificate_viewer_webui.cc	2014-01-13 15:16:24.000000000 +0100
@@ -228,7 +228,7 @@
   if (cert_index < 0)
     return;
 
-  NativeWebContentsModalDialog window =
+  _GtkWindow* window =
       platform_util::GetTopLevel(dialog_->dialog()->GetNativeDialog());
   ShowCertExportDialog(web_ui()->GetWebContents(),
                        window,
