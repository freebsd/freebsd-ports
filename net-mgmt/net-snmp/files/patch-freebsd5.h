--- include/net-snmp/system/freebsd5.h.orig	Wed Sep  1 00:13:46 2004
+++ include/net-snmp/system/freebsd5.h	Wed Sep  1 00:13:57 2004
@@ -7,6 +7,7 @@
 #define freebsd3 1
 /* freebsd5 is a superset of freebsd4 */
 #define freebsd4 1
+#define freebsd5 1
 
 #undef IFADDR_SYMBOL
 #define IFADDR_SYMBOL "in_ifaddrhead"
