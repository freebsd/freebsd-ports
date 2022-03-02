--- net/dns/host_resolver_manager.cc.orig	2022-02-28 16:54:41 UTC
+++ net/dns/host_resolver_manager.cc
@@ -3014,7 +3014,7 @@ HostResolverManager::HostResolverManager(
   NetworkChangeNotifier::AddConnectionTypeObserver(this);
   if (system_dns_config_notifier_)
     system_dns_config_notifier_->AddObserver(this);
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD) && \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_ANDROID)
   EnsureDnsReloaderInit();
 #endif
