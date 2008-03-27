--- include/net-snmp/system/freebsd5.h.orig	2006-08-18 08:14:20.000000000 +0900
+++ include/net-snmp/system/freebsd5.h	2008-03-25 21:12:05.556475473 +0900
@@ -1,6 +1,7 @@
 /* freebsd5 is a superset of freebsd4 */
 #include "freebsd4.h"
 #define freebsd4 freebsd4
+#define freebsd5 freebsd5
 
 /* don't define _KERNEL on FreeBSD 5.3 even if configure thinks we need it */
 #ifdef freebsd5
