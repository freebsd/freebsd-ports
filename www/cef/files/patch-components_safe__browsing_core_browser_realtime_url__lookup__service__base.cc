--- components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2026-08-12 09:02:10 UTC
+++ components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -121,7 +121,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_CHROME_OS;
 #elif BUILDFLAG(IS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif BUILDFLAG(IS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
