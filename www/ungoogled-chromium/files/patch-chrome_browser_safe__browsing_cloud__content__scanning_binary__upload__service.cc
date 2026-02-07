--- chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc
@@ -21,7 +21,7 @@
 #include "components/safe_browsing/core/common/safebrowsing_switches.h"
 #include "net/base/url_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/local_binary_upload_service_factory.h"
 #endif
 
