--- ./chrome/browser/ui/webui/certificate_viewer_webui.cc.orig	2014-04-30 22:42:10.000000000 +0200
+++ ./chrome/browser/ui/webui/certificate_viewer_webui.cc	2014-05-04 20:57:59.000000000 +0200
@@ -274,7 +274,7 @@
   if (cert_index < 0)
     return;
 
-  NativeWebContentsModalDialog window =
+  _GtkWindow* window =
       platform_util::GetTopLevel(dialog_->GetNativeWebContentsModalDialog());
   ShowCertExportDialog(web_ui()->GetWebContents(),
                        window,
