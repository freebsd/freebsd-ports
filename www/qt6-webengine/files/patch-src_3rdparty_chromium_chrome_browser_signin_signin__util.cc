--- src/3rdparty/chromium/chrome/browser/signin/signin_util.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/chrome/browser/signin/signin_util.cc
@@ -96,7 +96,7 @@ void CookiesMover::StartMovingCookies() {
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) && !BUILDFLAG(IS_QTWEBENGINE)
+#if (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_QTWEBENGINE)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
@@ -383,7 +383,7 @@ std::string SignedInStateToString(SignedInState state)
   }
 }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && !BUILDFLAG(IS_QTWEBENGINE)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_QTWEBENGINE)
 bool ShouldShowHistorySyncOptinScreen(Profile& profile) {
   if (GetSignedInState(IdentityManagerFactory::GetForProfile(&profile)) !=
       signin_util::SignedInState::kSignedIn) {
