--- chrome/renderer/chrome_content_renderer_client.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -1072,7 +1072,7 @@ WebPlugin* ChromeContentRendererClient::CreatePlugin(
       }
 
       case chrome::mojom::PluginStatus::kRestartRequired: {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         placeholder =
             create_blocked_plugin(IDR_BLOCKED_PLUGIN_HTML,
                                   l10n_util::GetStringFUTF16(
