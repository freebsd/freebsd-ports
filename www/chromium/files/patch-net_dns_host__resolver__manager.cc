--- net/dns/host_resolver_manager.cc.orig	2022-04-21 18:48:31 UTC
+++ net/dns/host_resolver_manager.cc
@@ -2996,7 +2996,7 @@ HostResolverManager::HostResolverManager(
   NetworkChangeNotifier::AddConnectionTypeObserver(this);
   if (system_dns_config_notifier_)
     system_dns_config_notifier_->AddObserver(this);
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD) && \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_ANDROID)
   EnsureDnsReloaderInit();
 #endif
