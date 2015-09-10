--- contrib/olsr/policy_varrw.hh.orig	2012-01-11 17:56:10 UTC
+++ contrib/olsr/policy_varrw.hh
@@ -45,7 +45,7 @@ class OlsrVarRW : public SingleVarRW {
     };
 
     OlsrVarRW(IPv4Net& network, IPv4& nexthop, uint32_t& metric,
-	      IPv4& originator, IPv4& main_addr, uint32_t vtype,
+	      IPv4& originator, IPv4& main_addr, uint32_t& vtype,
 	      PolicyTags& policytags);
 
     // SingleVarRW inteface:
