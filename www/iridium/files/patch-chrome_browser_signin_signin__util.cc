--- chrome/browser/signin/signin_util.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -50,7 +50,7 @@
 #include "services/network/public/mojom/cookie_manager.mojom.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_dialogs.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "components/strings/grit/components_strings.h"
@@ -101,7 +101,7 @@ CookiesMover::CookiesMover(base::WeakPtr<Profile> sour
 CookiesMover::~CookiesMover() = default;
 
 void CookiesMover::StartMovingCookies() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool allow_cookies_to_be_moved = base::FeatureList::IsEnabled(
       profile_management::features::kThirdPartyProfileManagement);
 #else
@@ -403,7 +403,7 @@ bool IsSyncingUserSelectableTypesAllowedByPolicy(
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool HasExplicitlyDisabledHistorySync(
     const syncer::SyncService* sync_service,
     const signin::IdentityManager* identity_manager) {
