--- src/3rdparty/chromium/net/dns/dns_reloader.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/net/dns/dns_reloader.cc
@@ -10,6 +10,7 @@
 // - there's not guarantee it exists at all. :(
 #if BUILDFLAG(IS_POSIX)
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 // This code only works on systems where the C library provides res_ninit(3) and
