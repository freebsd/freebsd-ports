--- net/dns/dns_config_service_posix.h.orig	2011-10-09 01:34:20.846923374 +0300
+++ net/dns/dns_config_service_posix.h	2011-10-09 01:35:52.752414016 +0300
@@ -6,6 +6,11 @@
 #define NET_DNS_DNS_CONFIG_SERVICE_POSIX_H_
 #pragma once
 
+#include "build/build_config.h"
+
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
 #include <resolv.h>
 
 #include "base/compiler_specific.h"
