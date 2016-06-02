--- src/plugins/ipmi_intf.c.orig	2016-05-06 14:48:54 UTC
+++ src/plugins/ipmi_intf.c
@@ -32,6 +32,7 @@
 #define _XOPEN_SOURCE 700
 #define _GNU_SOURCE 1
 #define _DARWIN_C_SOURCE 1
+#define __BSD_VISIBLE 1
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -48,6 +49,7 @@
 #include <ifaddrs.h>
 #include <unistd.h>
 #include <netdb.h>
+#define s6_addr16 __u6_addr.__u6_addr16
 #endif
 
 
