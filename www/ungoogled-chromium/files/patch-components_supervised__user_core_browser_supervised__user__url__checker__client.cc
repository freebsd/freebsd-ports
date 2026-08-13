--- components/supervised_user/core/browser/supervised_user_url_checker_client.cc.orig	2026-08-13 07:41:05 UTC
+++ components/supervised_user/core/browser/supervised_user_url_checker_client.cc
@@ -65,7 +65,7 @@ void OnResponse(
 
 FetcherConfig GetFetcherConfig(
     bool is_subject_to_family_link_parental_controls) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Supervised users on these platforms might get into a state where their
   // credentials are not available, so best-effort access mode is a graceful
   // fallback here.
