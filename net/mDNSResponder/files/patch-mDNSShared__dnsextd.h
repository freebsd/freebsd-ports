--- mDNSShared/dnsextd.h.orig	2010-01-18 21:39:34.000000000 +0900
+++ mDNSShared/dnsextd.h	2010-01-18 21:40:03.000000000 +0900
@@ -46,8 +46,9 @@
 #include <DNSCommon.h>
 #include <GenLinkedList.h>
 #include <sys/types.h>
-#include <sys/socket.h>
 #include <netinet/in.h>
+#include <sys/socket.h>
+#include <pthread.h>
 
 
 #define LLQ_TABLESIZE	1024	// !!!KRS make this dynamically growable
