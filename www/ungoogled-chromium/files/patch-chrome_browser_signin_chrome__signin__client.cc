--- chrome/browser/signin/chrome_signin_client.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/signin/chrome_signin_client.cc
@@ -162,7 +162,7 @@ signin_metrics::ProfileSignout kAlwaysAllowedSignoutSo
 std::string HatsSurveyTriggerForAccessPoint(
     signin_metrics::AccessPoint access_point) {
   switch (access_point) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case signin_metrics::AccessPoint::kAddressBubble:
       return kHatsSurveyTriggerIdentityAddressBubbleSignin;
     case signin_metrics::AccessPoint::kAvatarBubbleSignIn:
