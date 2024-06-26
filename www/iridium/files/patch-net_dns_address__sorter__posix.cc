--- net/dns/address_sorter_posix.cc.orig	2024-06-25 12:08:48 UTC
+++ net/dns/address_sorter_posix.cc
@@ -27,6 +27,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 #include <vector>
