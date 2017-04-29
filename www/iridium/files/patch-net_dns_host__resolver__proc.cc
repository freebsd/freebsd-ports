--- net/dns/host_resolver_proc.cc.orig	2017-04-19 19:06:36 UTC
+++ net/dns/host_resolver_proc.cc
@@ -194,7 +194,7 @@ int SystemHostResolverCall(const std::st
   hints.ai_socktype = SOCK_STREAM;
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
-    !defined(OS_ANDROID)
+    !defined(OS_ANDROID) && !defined(OS_FREEBSD)
   DnsReloaderMaybeReload();
 #endif
   int err = getaddrinfo(host.c_str(), NULL, &hints, &ai);
