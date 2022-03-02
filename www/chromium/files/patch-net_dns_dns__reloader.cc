--- net/dns/dns_reloader.cc.orig	2022-02-28 16:54:41 UTC
+++ net/dns/dns_reloader.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD) && \
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FUCHSIA)
 
 #include <resolv.h>
@@ -113,5 +113,5 @@ void DnsReloaderMaybeReload() {
 
 }  // namespace net
 
-#endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD)
+#endif  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD) &&
         // && !BUILDFLAG(IS_ANDROID)
