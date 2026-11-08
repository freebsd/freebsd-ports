--- content/browser/web_contents/web_contents_impl.cc.orig	2026-10-22 09:04:01 UTC
+++ content/browser/web_contents/web_contents_impl.cc
@@ -1468,7 +1468,7 @@ WebContentsImpl::WebContentsImpl(BrowserContext* brows
   renderer_preferences_.caret_blink_interval =
       native_theme->caret_blink_interval();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   renderer_preferences_.use_overlay_scrollbar =
       native_theme->use_overlay_scrollbar();
 #endif
@@ -12928,7 +12928,7 @@ void WebContentsImpl::OnNativeThemeUpdated(ui::NativeT
 
   const auto caret_blink_interval = observed_theme->caret_blink_interval();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const auto use_overlay_scrollbar = observed_theme->use_overlay_scrollbar();
 #endif
   bool renderer_preference_changed = false;
@@ -12937,7 +12937,7 @@ void WebContentsImpl::OnNativeThemeUpdated(ui::NativeT
     renderer_preference_changed = true;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (renderer_preferences_.use_overlay_scrollbar != use_overlay_scrollbar) {
     renderer_preferences_.use_overlay_scrollbar = use_overlay_scrollbar;
     renderer_preference_changed = true;
