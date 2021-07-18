--- components/safe_browsing/core/realtime/url_lookup_service_base.cc.orig	2021-04-14 18:41:00 UTC
+++ components/safe_browsing/core/realtime/url_lookup_service_base.cc
@@ -108,7 +108,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_FUCHSIA;
 #elif defined(OS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif defined(OS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
