--- chrome/browser/search_engine_choice/search_engine_choice_client_side_trial.cc.orig	2024-02-03 15:42:55 UTC
+++ chrome/browser/search_engine_choice/search_engine_choice_client_side_trial.cc
@@ -133,7 +133,7 @@ void RegisterLocalStatePrefs(PrefRegistrySimple* regis
 void SetUpIfNeeded(const base::FieldTrial::EntropyProvider& entropy_provider,
                    base::FeatureList* feature_list,
                    PrefService* local_state) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Platform not in scope for this client-side trial.
   return;
 #else
