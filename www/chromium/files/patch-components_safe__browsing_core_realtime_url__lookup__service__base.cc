--- components/safe_browsing/core/realtime/url_lookup_service_base.cc.orig	2021-07-19 18:45:14 UTC
+++ components/safe_browsing/core/realtime/url_lookup_service_base.cc
@@ -107,7 +107,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_FUCHSIA;
 #elif defined(OS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif defined(OS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
