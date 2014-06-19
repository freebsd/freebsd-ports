--- src/plugins/ipmi_intf.c.orig       2014-05-30 19:18:08.346626784 -0400
+++ src/plugins/ipmi_intf.c    2014-05-30 19:18:43.537804678 -0400
@@ -45,6 +45,7 @@
 #include <ifaddrs.h>
 #include <unistd.h>
 #include <netdb.h>
+#define s6_addr16 __u6_addr.__u6_addr16
 #endif

