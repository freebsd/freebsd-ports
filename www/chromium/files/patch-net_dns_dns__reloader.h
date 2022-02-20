--- net/dns/dns_reloader.h.orig	2022-02-07 13:39:41 UTC
+++ net/dns/dns_reloader.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_APPLE) && !defined(OS_BSD)
 namespace net {
 
 // Call on the network thread before calling DnsReloaderMaybeReload() anywhere.
