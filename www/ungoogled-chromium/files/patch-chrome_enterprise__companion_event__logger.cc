--- chrome/enterprise_companion/event_logger.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/enterprise_companion/event_logger.cc
@@ -127,7 +127,7 @@ proto::EnterpriseCompanionMetadata GetMetadata() {
   metadata.set_application_arch(proto::ARM64);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metadata.set_os_platform(proto::LINUX);
 #elif BUILDFLAG(IS_MAC)
   metadata.set_os_platform(proto::MAC);
