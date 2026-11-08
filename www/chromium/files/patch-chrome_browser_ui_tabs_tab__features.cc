--- chrome/browser/ui/tabs/tab_features.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -150,12 +150,12 @@
 #include "components/payments/core/features.h"
 #include "components/skills/features.h"
 #include "content/public/browser/navigation_controller.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_observer.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_tasks/contextual_tasks_tab_visit_tracker.h"
 #include "chrome/browser/record_replay/chrome_record_replay_client.h"
 #include "chrome/browser/ui/views/location_bar/record_replay_page_action_controller.h"
@@ -215,7 +215,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/hats/hats_helper.h"
 #include "chrome/browser/ui/performance_controls/performance_controls_hats_service_factory.h"
 #include "chrome/browser/ui/shared_highlighting/shared_highlighting_promo.h"
@@ -667,13 +667,13 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
 
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   desktop_session_duration_observer_ =
       metrics::DesktopSessionDurationObserver::MaybeCreate(tab.GetContents());
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
@@ -784,7 +784,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(enterprise_reporting::kSaasUsageReporting)) {
     saas_usage_navigation_observer_ =
         std::make_unique<enterprise_reporting::SaasUsageNavigationObserver>(
@@ -802,7 +802,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(multistep_filter::kMultistepFilter)) {
     filter_ui_controller_ =
         GetUserDataFactory()
@@ -1157,7 +1157,7 @@ void TabFeatures::WillDiscardContents(tabs::TabInterfa
           new_contents);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (hats_helper_) {
     hats_helper_ = std::make_unique<HatsHelper>(new_contents);
   }
@@ -1170,7 +1170,7 @@ void TabFeatures::WillDiscardContents(tabs::TabInterfa
       std::make_unique<FontPrewarmerTabHelper>(new_contents);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   desktop_session_duration_observer_ =
       metrics::DesktopSessionDurationObserver::MaybeCreate(new_contents);
 #endif
