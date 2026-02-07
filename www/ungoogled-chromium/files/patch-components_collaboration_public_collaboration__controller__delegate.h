--- components/collaboration/public/collaboration_controller_delegate.h.orig	2025-11-01 06:40:37 UTC
+++ components/collaboration/public/collaboration_controller_delegate.h
@@ -125,7 +125,7 @@ class CollaborationControllerDelegate {
         case Type::kSigninDisabledByPolicy:
           error_header = l10n_util::GetStringUTF8(
               IDS_COLLABORATION_ENTREPRISE_SIGNIN_DISABLED_HEADER);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           error_body = l10n_util::GetStringUTF8(
               base::FeatureList::IsEnabled(
                   syncer::kReplaceSyncPromosWithSignInPromos)
