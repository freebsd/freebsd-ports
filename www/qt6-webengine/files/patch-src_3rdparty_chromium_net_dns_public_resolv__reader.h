--- src/3rdparty/chromium/net/dns/public/resolv_reader.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/net/dns/public/resolv_reader.h
@@ -5,6 +5,7 @@
 #ifndef NET_DNS_PUBLIC_RESOLV_READER_H_
 #define NET_DNS_PUBLIC_RESOLV_READER_H_
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 #include <memory>
