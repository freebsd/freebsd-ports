--- chrome/browser/profiles/profile_manager.cc.orig	2025-03-09 21:38:10 UTC
+++ chrome/browser/profiles/profile_manager.cc
@@ -1495,7 +1495,7 @@ void ProfileManager::DoFinalInitForServices(Profile* p
   // Ensure NavigationPredictorKeyedService is started.
   NavigationPredictorKeyedServiceFactory::GetForProfile(profile);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   contextual_cueing::ContextualCueingServiceFactory::GetForProfile(profile);
 #endif
 
