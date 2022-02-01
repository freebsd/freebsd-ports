--- net/dns/public/resolv_reader.h.orig	2022-01-24 13:28:40 UTC
+++ net/dns/public/resolv_reader.h
@@ -5,6 +5,7 @@
 #ifndef NET_DNS_PUBLIC_RESOLV_READER_H_
 #define NET_DNS_PUBLIC_RESOLV_READER_H_
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 #include <memory>
