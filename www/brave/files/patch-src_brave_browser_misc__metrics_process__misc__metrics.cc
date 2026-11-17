--- src/brave/browser/misc_metrics/process_misc_metrics.cc.orig	2026-10-18 18:43:23 UTC
+++ src/brave/browser/misc_metrics/process_misc_metrics.cc
@@ -18,6 +18,7 @@
 #include "components/prefs/pref_change_registrar.h"
 #include "components/prefs/pref_registry_simple.h"
 #include "components/prefs/pref_service.h"
+#include "third_party/widevine/cdm/buildflags.h"
 #if !BUILDFLAG(IS_ANDROID)
 #include "brave/browser/misc_metrics/default_browser_monitor_delegate_impl.h"
 #include "brave/browser/misc_metrics/vertical_tab_metrics.h"
@@ -34,10 +35,17 @@ namespace misc_metrics {
 ProcessMiscMetrics::ProcessMiscMetrics(PrefService* local_state)
     : local_state_(local_state) {
   pref_change_registrar_.Init(local_state);
+#if BUILDFLAG(ENABLE_WIDEVINE)
+  // kWidevineEnabled is registered by //brave/browser/widevine, whose BUILD.gn
+  // asserts enable_widevine.  With Widevine off the pref is never registered,
+  // and reaching for it fails the CHECK in PrefService at startup.  The other
+  // two readers of this pref, brave_renderer_updater.cc and
+  // brave_default_extensions_handler.cc, already guard themselves this way.
   pref_change_registrar_.Add(
       kWidevineEnabled,
       base::BindRepeating(&ProcessMiscMetrics::ReportSimpleMetrics,
                           base::Unretained(this)));
+#endif
 
 #if !BUILDFLAG(IS_ANDROID)
   menu_metrics_ = std::make_unique<MenuMetrics>(local_state);
@@ -118,8 +126,10 @@ Web3Metrics& ProcessMiscMetrics::web3_me
 }
 
 void ProcessMiscMetrics::ReportSimpleMetrics() {
+#if BUILDFLAG(ENABLE_WIDEVINE)
   UMA_HISTOGRAM_BOOLEAN(kWidevineEnabledHistogramName,
                         local_state_->GetBoolean(kWidevineEnabled));
+#endif
 }
 
 void ProcessMiscMetrics::RegisterPrefs(PrefRegistrySimple* registry) {
