--- chrome/browser/signin/signin_util.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/signin/signin_util.cc
@@ -43,7 +43,7 @@
 #include "google_apis/gaia/gaia_id.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/dialogs/browser_dialogs.h"
 #include "components/strings/grit/components_strings.h"
 #include "ui/base/interaction/element_identifier.h"
@@ -325,7 +325,7 @@ bool IsSyncingUserSelectableTypesAllowedByPolicy(
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool HasExplicitlyDisabledHistorySync(
     const syncer::SyncService* sync_service,
     const signin::IdentityManager* identity_manager) {
