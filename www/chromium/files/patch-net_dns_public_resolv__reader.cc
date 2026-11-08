--- net/dns/public/resolv_reader.cc.orig	2026-09-25 15:26:43 UTC
+++ net/dns/public/resolv_reader.cc
@@ -31,7 +31,7 @@ std::unique_ptr<ScopedResState> ResolvReader::GetResSt
 }
 
 bool ResolvReader::IsLikelySystemdResolved() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Look for a single 127.0.0.53:53 nameserver endpoint. The only known
   // significant usage of such a configuration is the systemd-resolved local
   // resolver, so it is then a fairly safe assumption that any DNS queries to
