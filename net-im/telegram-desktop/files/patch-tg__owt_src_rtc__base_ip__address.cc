--- tg_owt/src/rtc_base/ip_address.cc.orig	2020-08-30 09:41:57 UTC
+++ tg_owt/src/rtc_base/ip_address.cc
@@ -15,6 +15,7 @@
 #include <netinet/in_systm.h>
 #endif
 #ifndef __native_client__
+#include <sys/types.h>
 #include <netinet/ip.h>
 #endif
 #include <netdb.h>
