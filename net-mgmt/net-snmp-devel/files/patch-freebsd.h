--- include/net-snmp/system/freebsd.h.orig	Sat Apr  3 14:56:45 2004
+++ include/net-snmp/system/freebsd.h	Sat Apr  3 14:56:59 2004
@@ -6,7 +6,7 @@
  * udp_inpcb list symbol 
  */
 #undef INP_NEXT_SYMBOL
-#define INP_NEXT_SYMBOL inp_next
+#define INP_NEXT_SYMBOL inp_list.le_next
 
 #undef TCP_TTL_SYMBOL
 #define TCP_TTL_SYMBOL "ip_defttl"
