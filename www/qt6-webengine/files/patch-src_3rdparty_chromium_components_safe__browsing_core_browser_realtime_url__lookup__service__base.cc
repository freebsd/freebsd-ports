--- src/3rdparty/chromium/components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -110,7 +110,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_CHROME_OS;
 #elif BUILDFLAG(IS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif BUILDFLAG(IS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
