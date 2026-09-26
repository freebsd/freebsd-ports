--- components/autofill/core/browser/payments/payments_requests/payments_request.cc.orig	2026-09-25 15:26:43 UTC
+++ components/autofill/core/browser/payments/payments_requests/payments_request.cc
@@ -254,7 +254,7 @@ PaymentsRequest::ClientType PaymentsRequest::GetChrome
   return ClientType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return ClientType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ClientType::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ClientType::kChromeOs;
