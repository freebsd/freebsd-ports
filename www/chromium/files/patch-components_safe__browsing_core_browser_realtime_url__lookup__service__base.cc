--- components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2022-02-07 13:39:41 UTC
+++ components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -107,7 +107,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_FUCHSIA;
 #elif defined(OS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif defined(OS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
