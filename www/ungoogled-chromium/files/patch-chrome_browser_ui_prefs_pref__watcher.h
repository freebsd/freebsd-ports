--- chrome/browser/ui/prefs/pref_watcher.h.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/ui/prefs/pref_watcher.h
@@ -53,7 +53,7 @@ class PrefWatcher : public KeyedService,
   // blink::RendererPreferences.
   std::set<raw_ptr<PrefsTabHelper, SetExperimental>> tab_helpers_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   friend class PrimaryPastePrefHelper;
   std::unique_ptr<PrimaryPastePrefHelper> primary_paste_pref_helper_;
 #endif
