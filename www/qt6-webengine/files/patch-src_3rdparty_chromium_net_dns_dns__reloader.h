--- src/3rdparty/chromium/net/dns/dns_reloader.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/dns/dns_reloader.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 namespace net {
 
 // Call on the network thread before calling DnsReloaderMaybeReload() anywhere.
