--- net/dns/host_resolver_proc.cc.orig	2019-04-30 22:22:54 UTC
+++ net/dns/host_resolver_proc.cc
@@ -197,7 +197,7 @@ int SystemHostResolverCall(const std::string& host,
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
                                                 base::BlockingType::WILL_BLOCK);
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
   DnsReloaderMaybeReload();
 #endif
