--- components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2024-08-01 05:47:53 UTC
+++ components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -108,7 +108,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_FUCHSIA;
 #elif BUILDFLAG(IS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif BUILDFLAG(IS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
