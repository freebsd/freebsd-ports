--- net/dns/host_resolver_manager.cc.orig	2022-10-29 17:50:56 UTC
+++ net/dns/host_resolver_manager.cc
@@ -3127,7 +3127,7 @@ HostResolverManager::HostResolverManager(
   }
   if (system_dns_config_notifier_)
     system_dns_config_notifier_->AddObserver(this);
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD) && \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_ANDROID)
   EnsureDnsReloaderInit();
 #endif
