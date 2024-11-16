--- chrome/browser/policy/device_management_service_configuration.cc.orig	2024-11-14 07:57:23 UTC
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -23,7 +23,7 @@
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) ||           \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
-     !BUILDFLAG(IS_ANDROID))
+     !BUILDFLAG(IS_ANDROID)) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
 #endif
