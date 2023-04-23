--- src/3rdparty/chromium/net/dns/host_resolver_system_task.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/net/dns/host_resolver_system_task.cc
@@ -310,8 +310,8 @@ void EnsureSystemHostResolverCallReady() {
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
