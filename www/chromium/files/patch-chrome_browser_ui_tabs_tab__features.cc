--- chrome/browser/ui/tabs/tab_features.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -215,12 +215,12 @@
 #include "components/skills/features.h"
 #include "components/zoom/zoom_controller.h"
 #include "content/public/browser/navigation_controller.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_observer.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_tasks/contextual_tasks_tab_navigation_observer.h"
 #include "chrome/browser/contextual_tasks/contextual_tasks_tab_visit_tracker.h"
 #include "chrome/browser/contextual_tasks/search_journey_tab_feature.h"
@@ -310,7 +310,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/hats/hats_helper.h"
 #include "chrome/browser/ui/performance_controls/performance_controls_hats_service_factory.h"
 #include "chrome/browser/ui/shared_highlighting/shared_highlighting_promo.h"
@@ -890,13 +890,13 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
 
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
 
@@ -1040,7 +1040,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(enterprise_reporting::kSaasUsageReporting)) {
     saas_usage_navigation_observer_ =
         std::make_unique<enterprise_reporting::SaasUsageNavigationObserver>(
@@ -1058,7 +1058,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(multistep_filter::kMultistepFilter)) {
     filter_ui_controller_ =
         GetUserDataFactory()
@@ -1757,7 +1757,7 @@ void TabFeatures::WillDiscardContents(tabs::TabInterfa
           new_contents);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (saas_usage_navigation_observer_) {
     saas_usage_navigation_observer_ =
         std::make_unique<enterprise_reporting::SaasUsageNavigationObserver>(
@@ -1775,7 +1775,7 @@ void TabFeatures::WillDiscardContents(tabs::TabInterfa
       std::make_unique<FontPrewarmerTabHelper>(new_contents);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   desktop_session_duration_observer_ =
       metrics::DesktopSessionDurationObserver::MaybeCreate(new_contents);
 #endif
