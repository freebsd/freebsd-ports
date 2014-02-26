--- ./contrib/olsr/policy_varrw.hh.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./contrib/olsr/policy_varrw.hh	2014-02-26 21:17:13.000000000 +0000
@@ -45,7 +45,7 @@
     };
 
     OlsrVarRW(IPv4Net& network, IPv4& nexthop, uint32_t& metric,
-	      IPv4& originator, IPv4& main_addr, uint32_t vtype,
+	      IPv4& originator, IPv4& main_addr, uint32_t& vtype,
 	      PolicyTags& policytags);
 
     // SingleVarRW inteface:
