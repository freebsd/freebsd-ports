--- components/autofill/core/browser/payments/payments_requests/payments_request.cc.orig	2026-11-17 21:17:00 UTC
+++ components/autofill/core/browser/payments/payments_requests/payments_request.cc
@@ -250,7 +250,7 @@ PaymentsRequest::ClientType PaymentsRequest::GetChrome
   return ClientType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return ClientType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ClientType::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ClientType::kChromeOs;
