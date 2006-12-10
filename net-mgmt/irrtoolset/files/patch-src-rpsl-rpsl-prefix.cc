--- src/rpsl/rpsl/prefix.cc.orig	2004-07-30 12:58:14.000000000 +0200
+++ src/rpsl/rpsl/prefix.cc
@@ -1216,10 +1216,13 @@ void MPPrefixRanges::except(MPPrefixRang
    assign(result.begin(), result.end());
 }
 
+// contains methods rewritten by spz according to hint from Hagen Boehm
 bool MPPrefixRanges::contains(IPAddr ip) const {
    MPPrefixRanges::const_iterator p;
    for (p = begin(); p != end(); ++p) {
-     if (p->ipv4 && (p->ipv4->get_ipaddr() == ip.get_ipaddr())) 
+     if (p->ipv4
+		&& p->ipv4->get_ipaddr() == ip.get_ipaddr()
+		&& p->ipv4->get_length() == ip.get_length() )
        return true;
    }
    return false;
@@ -1228,7 +1231,9 @@ bool MPPrefixRanges::contains(IPAddr ip)
 bool MPPrefixRanges::contains(IPv6Addr ip) const {
    MPPrefixRanges::const_iterator p;
    for (p = begin(); p != end(); ++p) {
-     if (p->ipv6 && (*(p->ipv6->get_ipaddr()) == *(ip.get_ipaddr())) )
+     if (p->ipv6
+		&& p->ipv6->get_ipaddr() == ip.get_ipaddr()
+		&& p->ipv6->get_length() == ip.get_length() )
        return true;
    }
    return false;
