--- src/3rdparty/chromium/net/dns/public/scoped_res_state.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/dns/public/scoped_res_state.h
@@ -5,6 +5,7 @@
 #ifndef NET_DNS_PUBLIC_SCOPED_RES_STATE_H_
 #define NET_DNS_PUBLIC_SCOPED_RES_STATE_H_
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 #include "build/build_config.h"
