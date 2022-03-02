--- net/dns/host_resolver_proc.cc.orig	2022-02-28 16:54:41 UTC
+++ net/dns/host_resolver_proc.cc
@@ -19,10 +19,6 @@
 #include "net/dns/dns_util.h"
 #include "net/dns/host_resolver.h"
 
-#if BUILDFLAG(IS_OPENBSD)
-#define AI_ADDRCONFIG 0
-#endif
-
 namespace net {
 
 HostResolverProc* HostResolverProc::default_proc_ = nullptr;
@@ -177,7 +173,7 @@ int SystemHostResolverCall(const std::string& host,
                                                 base::BlockingType::WILL_BLOCK);
 
 #if BUILDFLAG(IS_POSIX) && \
-    !(BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_ANDROID))
+    !(BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_ANDROID))
   DnsReloaderMaybeReload();
 #endif
   absl::optional<AddressInfo> ai;
