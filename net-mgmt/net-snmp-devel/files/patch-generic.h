--- include/net-snmp/system/generic.h.orig	2008-03-26 10:28:25.802233395 +0900
+++ include/net-snmp/system/generic.h	2008-03-26 10:29:40.629721291 +0900
@@ -1,3 +1,5 @@
+#ifndef __NET_SNMP_SYSTEM_GENERIC_H__
+#define __NET_SNMP_SYSTEM_GENERIC_H__
 
 #define bsdlike bsdlike
 
@@ -72,3 +74,5 @@
  */
 #define INP_NEXT_SYMBOL inp_next
 #define INP_PREV_SYMBOL inp_prev
+
+#endif /* !__NET_SNMP_SYSTEM_GENERIC_H__ */
