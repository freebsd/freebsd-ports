--- net/dns/host_resolver_system_task.cc.orig	2022-11-30 08:12:58 UTC
+++ net/dns/host_resolver_system_task.cc
@@ -310,8 +310,8 @@ void HostResolverSystemTask::OnLookupComplete(const ui
 }
 
 void EnsureSystemHostResolverCallReady() {
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD) && \
-    !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && \
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
   EnsureDnsReloaderInit();
 #elif BUILDFLAG(IS_WIN)
   EnsureWinsockInit();
@@ -397,7 +397,7 @@ int SystemHostResolverCall(const std::string& host,
                                                 base::BlockingType::WILL_BLOCK);
 
 #if BUILDFLAG(IS_POSIX) && \
-    !(BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_ANDROID))
+    !(BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
   DnsReloaderMaybeReload();
 #endif
   auto [ai, err, os_error] = AddressInfo::Get(host, hints, nullptr, network);
