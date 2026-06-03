--- generator/net_snmp.go.orig	2026-03-02 17:36:00 UTC
+++ generator/net_snmp.go
@@ -19,6 +19,7 @@ package main
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/mib_api.h>
 #include <net-snmp/agent/agent_callbacks.h>
+#include <net-snmp/library/snmp_api.h>
 #include <net-snmp/library/default_store.h>
 #include <net-snmp/library/parse.h>
 #include <unistd.h>
@@ -41,6 +42,9 @@ struct tc {
   struct enum_list *enums;
   struct range_list *ranges;
   char           *description;
+#if defined(SNMP_FLAGS_SESSION_USER)
+  int             lineno;
+#endif
 #if !defined(NETSNMP_DS_LIB_ADD_FORWARDER_INFO)
 } tclist[MAXTC];
 int tc_alloc = MAXTC;
