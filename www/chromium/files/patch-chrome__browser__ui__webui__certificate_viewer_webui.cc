--- ./chrome/browser/ui/webui/certificate_viewer_webui.cc.orig	2014-04-24 22:35:00.000000000 +0200
+++ ./chrome/browser/ui/webui/certificate_viewer_webui.cc	2014-04-24 23:23:43.000000000 +0200
@@ -229,7 +229,7 @@
   if (cert_index < 0)
     return;
 
-  NativeWebContentsModalDialog window =
+  _GtkWindow* window =
       platform_util::GetTopLevel(dialog_->dialog()->GetNativeDialog());
   ShowCertExportDialog(web_ui()->GetWebContents(),
                        window,
