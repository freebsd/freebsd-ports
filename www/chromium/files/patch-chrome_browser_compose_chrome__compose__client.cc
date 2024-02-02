--- chrome/browser/compose/chrome_compose_client.cc.orig	2024-01-30 07:53:34 UTC
+++ chrome/browser/compose/chrome_compose_client.cc
@@ -170,14 +170,14 @@ void ChromeComposeClient::CloseUI(compose::mojom::Clos
 void ChromeComposeClient::ApproveConsent() {
   pref_service_->SetBoolean(
       unified_consent::prefs::kPageContentCollectionEnabled, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pref_service_->SetBoolean(prefs::kPrefHasAcceptedComposeConsent, true);
 #endif
   UpdateAllSessionsWithConsentApproved();
 }
 
 void ChromeComposeClient::AcknowledgeConsentDisclaimer() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pref_service_->SetBoolean(prefs::kPrefHasAcceptedComposeConsent, true);
 #endif
   UpdateAllSessionsWithConsentApproved();
