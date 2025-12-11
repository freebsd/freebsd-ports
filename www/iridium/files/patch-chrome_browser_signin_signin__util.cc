--- chrome/browser/signin/signin_util.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -50,7 +50,7 @@
 #include "services/network/public/mojom/cookie_manager.mojom.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_dialogs.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "components/strings/grit/components_strings.h"
@@ -97,7 +97,7 @@ CookiesMover::CookiesMover(base::WeakPtr<Profile> sour
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
@@ -399,7 +399,7 @@ bool IsSyncingUserSelectableTypesAllowedByPolicy(
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool HasExplicitlyDisabledHistorySync(Profile& profile) {
   // If the user is signed out, we cannot know if the toggles were interacted
   // with or not.
