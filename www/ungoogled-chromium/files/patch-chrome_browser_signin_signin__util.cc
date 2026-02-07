--- chrome/browser/signin/signin_util.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -49,7 +49,7 @@
 #include "services/network/public/mojom/cookie_manager.mojom.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_dialogs.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "components/strings/grit/components_strings.h"
@@ -374,7 +374,7 @@ bool IsSyncingUserSelectableTypesAllowedByPolicy(
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool HasExplicitlyDisabledHistorySync(
     const syncer::SyncService* sync_service,
     const signin::IdentityManager* identity_manager) {
