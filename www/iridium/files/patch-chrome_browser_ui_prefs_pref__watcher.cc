--- chrome/browser/ui/prefs/pref_watcher.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/ui/prefs/pref_watcher.cc
@@ -37,7 +37,7 @@
 #include "components/browser_ui/accessibility/android/font_size_prefs_android.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/primary_paste_pref_observer.h"
 #endif
@@ -91,7 +91,7 @@ const char* const kWebPrefsToObserve[] = {
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A helper class to handle notifying about changes in the
 // Primary Paste/Middle Click Paste preference on Linux.
 class PrimaryPastePrefHelper : public ui::PrimaryPastePrefObserver {
@@ -122,7 +122,7 @@ class PrimaryPastePrefHelper : public ui::PrimaryPaste
 PrefWatcher::PrefWatcher(Profile* profile) : profile_(profile) {
   native_theme_observation_.Observe(ui::NativeTheme::GetInstanceForWeb());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   primary_paste_pref_helper_ = std::make_unique<PrimaryPastePrefHelper>(this);
 #endif
 
