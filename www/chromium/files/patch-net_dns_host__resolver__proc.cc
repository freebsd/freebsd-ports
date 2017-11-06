--- net/dns/host_resolver_proc.cc.orig	2017-09-05 21:05:22.000000000 +0200
+++ net/dns/host_resolver_proc.cc	2017-09-06 20:49:21.939725000 +0200
@@ -190,7 +190,7 @@
   // Restrict result set to only this socket type to avoid duplicates.
   hints.ai_socktype = SOCK_STREAM;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
   DnsReloaderMaybeReload();
 #endif
