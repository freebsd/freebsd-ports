--- remoting/host/agent_integration_configurator.cc.orig	2026-11-19 12:25:27 UTC
+++ remoting/host/agent_integration_configurator.cc
@@ -16,7 +16,7 @@ AgentIntegrationConfigurator::AgentIntegrationConfigur
 
 AgentIntegrationConfigurator::~AgentIntegrationConfigurator() = default;
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 // static
 void AgentIntegrationConfigurator::IsSupported(IsSupportedCallback callback) {
