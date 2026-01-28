--- chrome/renderer/chrome_content_renderer_client.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -183,7 +183,7 @@
 #include "v8/include/v8-isolate.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -419,7 +419,7 @@ void ChromeContentRendererClient::RenderThreadStarted(
   WebSecurityPolicy::RegisterURLSchemeAsExtension(
       WebString::FromASCII(extensions::kExtensionScheme));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebSecurityPolicy::RegisterURLSchemeAsIsolatedApp(
       WebString::FromASCII(webapps::kIsolatedAppScheme));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -488,7 +488,7 @@ void ChromeContentRendererClient::RenderThreadStarted(
       WebString::FromASCII(chrome::kChromeSearchScheme));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWAs can be enabled by either the feature flag or by enterprise
   // policy. In either case the kEnableIsolatedWebAppsInRenderer flag is passed
   // to the renderer process.
