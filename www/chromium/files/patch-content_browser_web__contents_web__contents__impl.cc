--- content/browser/web_contents/web_contents_impl.cc.orig	2026-08-31 10:59:09 UTC
+++ content/browser/web_contents/web_contents_impl.cc
@@ -1372,7 +1372,7 @@ WebContentsImpl::WebContentsImpl(BrowserContext* brows
       SlowWebPreferenceCache::GetInstance());
   renderer_preferences_.caret_blink_interval =
       native_theme->caret_blink_interval();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   renderer_preferences_.use_overlay_scrollbar =
       native_theme->use_overlay_scrollbar();
 #endif
@@ -12465,7 +12465,7 @@ void WebContentsImpl::OnNativeThemeUpdated(ui::NativeT
   HandleColorRelatedStateChanges();
 
   const auto caret_blink_interval = observed_theme->caret_blink_interval();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const auto use_overlay_scrollbar = observed_theme->use_overlay_scrollbar();
 #endif
   bool renderer_preference_changed = false;
@@ -12473,7 +12473,7 @@ void WebContentsImpl::OnNativeThemeUpdated(ui::NativeT
     renderer_preferences_.caret_blink_interval = caret_blink_interval;
     renderer_preference_changed = true;
   }
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (renderer_preferences_.use_overlay_scrollbar != use_overlay_scrollbar) {
     renderer_preferences_.use_overlay_scrollbar = use_overlay_scrollbar;
     renderer_preference_changed = true;
