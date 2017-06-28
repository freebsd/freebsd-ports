--- net/dns/host_resolver_proc.cc.orig	2017-06-05 19:03:10 UTC
+++ net/dns/host_resolver_proc.cc
@@ -194,7 +194,7 @@ int SystemHostResolverCall(const std::string& host,
   hints.ai_socktype = SOCK_STREAM;
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
-    !defined(OS_ANDROID)
+    !defined(OS_ANDROID) && !defined(OS_FREEBSD)
   DnsReloaderMaybeReload();
 #endif
   int err = getaddrinfo(host.c_str(), NULL, &hints, &ai);
