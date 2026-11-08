--- chrome/browser/glic/host/glic_web_client_handler.cc.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/glic/host/glic_web_client_handler.cc
@@ -136,7 +136,7 @@ namespace glic {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableGlicAiAvatarRing, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
@@ -1241,7 +1241,7 @@ class GlicWebClientHandler
 #else
     result->local_profile_name =
         base::UTF16ToUTF8(entry->GetLocalProfileName());
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     result->has_avatar_ring =
         base::FeatureList::IsEnabled(kEnableGlicAiAvatarRing) &&
         ShouldShowAvatarGradientRing(profile_);
