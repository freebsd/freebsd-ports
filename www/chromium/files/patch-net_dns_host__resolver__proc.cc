--- net/dns/host_resolver_proc.cc.orig	2022-02-07 13:39:41 UTC
+++ net/dns/host_resolver_proc.cc
@@ -19,10 +19,6 @@
 #include "net/dns/dns_util.h"
 #include "net/dns/host_resolver.h"
 
-#if defined(OS_OPENBSD)
-#define AI_ADDRCONFIG 0
-#endif
-
 namespace net {
 
 HostResolverProc* HostResolverProc::default_proc_ = nullptr;
@@ -177,7 +173,7 @@ int SystemHostResolverCall(const std::string& host,
                                                 base::BlockingType::WILL_BLOCK);
 
 #if defined(OS_POSIX) && \
-    !(defined(OS_APPLE) || defined(OS_OPENBSD) || defined(OS_ANDROID))
+    !(defined(OS_APPLE) || defined(OS_BSD) || defined(OS_ANDROID))
   DnsReloaderMaybeReload();
 #endif
   absl::optional<AddressInfo> ai;
