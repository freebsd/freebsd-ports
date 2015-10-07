--- contrib/olsr/policy_varrw.cc.orig	2012-01-11 17:56:10 UTC
+++ contrib/olsr/policy_varrw.cc
@@ -39,7 +39,7 @@
 #include "policy_varrw.hh"
 
 OlsrVarRW::OlsrVarRW(IPv4Net& network, IPv4& nexthop, uint32_t& metric,
-		     IPv4& originator, IPv4& main_addr, uint32_t vtype,
+		     IPv4& originator, IPv4& main_addr, uint32_t& vtype,
 		     PolicyTags& policytags)
     : _network(network), _nexthop(nexthop), _metric(metric),
       _originator(originator), _main_addr(main_addr), _vtype(vtype),
