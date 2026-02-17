--- chrome/enterprise_companion/event_logger.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/enterprise_companion/event_logger.cc
@@ -126,7 +126,7 @@ proto::EnterpriseCompanionMetadata GetMetadata() {
   metadata.set_application_arch(proto::ARM64);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metadata.set_os_platform(proto::LINUX);
 #elif BUILDFLAG(IS_MAC)
   metadata.set_os_platform(proto::MAC);
