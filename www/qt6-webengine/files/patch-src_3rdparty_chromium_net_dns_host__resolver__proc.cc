--- src/3rdparty/chromium/net/dns/host_resolver_proc.cc.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/net/dns/host_resolver_proc.cc
@@ -15,10 +15,6 @@
 #include "net/base/net_errors.h"
 #include "net/dns/host_resolver_system_task.h"
 
-#if BUILDFLAG(IS_OPENBSD)
-#define AI_ADDRCONFIG 0
-#endif
-
 namespace net {
 
 HostResolverProc* HostResolverProc::default_proc_ = nullptr;
