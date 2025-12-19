--- src/3rdparty/chromium/chrome/browser/signin/signin_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/signin/signin_util.cc
@@ -86,7 +86,7 @@ void CookiesMover::StartMovingCookies() {
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) && !BUILDFLAG(IS_QTWEBENGINE)
+#if (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_QTWEBENGINE)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
