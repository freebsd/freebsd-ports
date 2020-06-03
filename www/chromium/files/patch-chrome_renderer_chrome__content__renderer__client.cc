--- chrome/renderer/chrome_content_renderer_client.cc.orig	2020-05-13 18:40:25 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -1059,7 +1059,7 @@ WebPlugin* ChromeContentRendererClient::CreatePlugin(
       }
 
       case chrome::mojom::PluginStatus::kRestartRequired: {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         placeholder =
             create_blocked_plugin(IDR_BLOCKED_PLUGIN_HTML,
                                   l10n_util::GetStringFUTF16(
