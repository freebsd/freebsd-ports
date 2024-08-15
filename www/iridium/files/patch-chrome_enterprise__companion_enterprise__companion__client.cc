--- chrome/enterprise_companion/enterprise_companion_client.cc.orig	2024-08-01 05:47:53 UTC
+++ chrome/enterprise_companion/enterprise_companion_client.cc
@@ -9,7 +9,7 @@ namespace enterprise_companion {
 mojo::NamedPlatformChannel::ServerName GetServerName() {
 #if BUILDFLAG(IS_MAC)
   return "org.chromium.ChromeEnterpriseCompanion.service";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "/run/Chromium/ChromeEnterpriseCompanion/service.sk";
 #elif BUILDFLAG(IS_WIN)
   return L"ChromeEnterpriseCompanionService";
