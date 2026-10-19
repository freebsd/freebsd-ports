--- chrome/browser/ui/webui/interstitials/interstitial_ui.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/ui/webui/interstitials/interstitial_ui.cc
@@ -77,12 +77,12 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_blocked_sites.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_page_youtube.h"
 #endif
 
@@ -409,7 +409,7 @@ std::unique_ptr<EnterpriseWarnPage> CreateEnterpriseWa
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<SupervisedUserVerificationPageForYouTube>
 CreateSupervisedUserVerificationPageForYouTube(
     content::WebContents* web_contents,
@@ -429,7 +429,7 @@ CreateSupervisedUserVerificationPageForYouTube(
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::unique_ptr<SupervisedUserVerificationPageForBlockedSites>
 CreateSupervisedUserVerificationPageForBlockedSites(
     content::WebContents* web_contents,
@@ -639,7 +639,7 @@ void InterstitialHTMLSource::StartDataRequest(
     interstitial_delegate = CreateInsecureFormPage(web_contents);
   } else if (path_without_query == "/https_only") {
     interstitial_delegate = CreateHttpsOnlyModePage(web_contents);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (path_without_query == "/supervised-user-verify") {
     interstitial_delegate = CreateSupervisedUserVerificationPageForYouTube(
         web_contents, /*is_main_frame=*/true);
@@ -648,7 +648,7 @@ void InterstitialHTMLSource::StartDataRequest(
         web_contents, /*is_main_frame=*/false);
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   } else if (path_without_query == "/supervised-user-verify-blocked-site") {
     interstitial_delegate = CreateSupervisedUserVerificationPageForBlockedSites(
         web_contents, /*is_main_frame=*/true);
