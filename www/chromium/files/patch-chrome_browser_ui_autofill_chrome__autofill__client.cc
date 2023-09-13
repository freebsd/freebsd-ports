--- chrome/browser/ui/autofill/chrome_autofill_client.cc.orig	2023-09-13 12:11:42 UTC
+++ chrome/browser/ui/autofill/chrome_autofill_client.cc
@@ -1100,7 +1100,14 @@ void ChromeAutofillClient::PropagateAutofillPrediction
           &renderer_form);
     }
 
+#if defined(__clang__) && (__clang_major__ >= 16)
     for (const auto& [frame_token, frame_forms] : renderer_forms_by_frame) {
+#else
+    for (const auto& r_f : renderer_forms_by_frame) {
+      const auto& [f_t, f_f] = r_f;
+      const auto& frame_token = f_t;
+      const auto& frame_forms = f_f;
+#endif
       // Attempt to find the RFH with this `frame_token`.
       content::RenderFrameHost* rfh = nullptr;
       GetWebContents().ForEachRenderFrameHost(
