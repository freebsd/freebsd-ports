--- chrome/renderer/chrome_content_renderer_client.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -187,7 +187,7 @@
 #include "v8/include/v8-isolate.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -426,7 +426,7 @@ void ChromeContentRendererClient::RenderThreadStarted(
   WebSecurityPolicy::RegisterURLSchemeAsExtension(
       WebString::FromAscii(extensions::kExtensionScheme));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebSecurityPolicy::RegisterURLSchemeAsIsolatedApp(
       WebString::FromAscii(webapps::kIsolatedAppScheme));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -505,7 +505,7 @@ void ChromeContentRendererClient::RenderThreadStarted(
       WebString::FromAscii(chrome::kChromeSearchScheme));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWAs can be enabled by either the feature flag or by enterprise
   // policy. In either case the kEnableIsolatedWebAppsInRenderer flag is passed
   // to the renderer process.
