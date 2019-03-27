--- src/3rdparty/chromium/net/dns/host_resolver_proc.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/dns/host_resolver_proc.cc
@@ -195,7 +195,7 @@ int SystemHostResolverCall(const std::string& host,
   // current process during that time.
   base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::WILL_BLOCK);
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD) && \
     !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
   DnsReloaderMaybeReload();
 #endif
