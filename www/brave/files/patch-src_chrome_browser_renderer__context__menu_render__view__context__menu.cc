--- src/chrome/browser/renderer_context_menu/render_view_context_menu.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/renderer_context_menu/render_view_context_menu.cc
@@ -292,7 +292,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -6127,7 +6127,7 @@ void RenderViewContextMenu::AppendRevise
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderViewContextMenu::IsLinkToIsolatedWebApp() const {
   // Using `unfiltered_link_url`, because `link_url` is being replaced with
   // about:blank#blocked if the source is a normal site.
