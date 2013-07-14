--- lib/SNMP_Session.pm.orig	2011-01-31 14:10:12.000000000 +0600
+++ lib/SNMP_Session.pm	2011-01-31 14:11:20.000000000 +0600
@@ -146,7 +146,7 @@
 
     if (eval {local $SIG{__DIE__};require Socket6;} &&
        eval {local $SIG{__DIE__};require IO::Socket::INET6; IO::Socket::INET6->VERSION("1.26");}) {
-	import Socket6;
+       	Socket6->import(qw(inet_pton inet_ntop getaddrinfo));
 	$ipv6_addr_len = length(pack_sockaddr_in6(161, inet_pton(AF_INET6(), "::1")));
 	$SNMP_Session::ipv6available = 1;
     }
@@ -549,7 +549,7 @@
     # complaining about AF_INET6 when Socket6 is not available
 
     if( (defined $ipv6_addr_len) && (length $addr == $ipv6_addr_len)) {
-	($port,$addrunpack) = unpack_sockaddr_in6 ($addr);
+	($port,$addrunpack) = Socket6::unpack_sockaddr_in6 ($addr);
 	$addrstr = inet_ntop (AF_INET6(), $addrunpack);
     } else {
 	($port,$addrunpack) = unpack_sockaddr_in ($addr);
@@ -605,7 +605,7 @@
 BEGIN {
     if($SNMP_Session::ipv6available) {
 	import IO::Socket::INET6;
-	import Socket6;
+	Socket6->import(qw(inet_pton inet_ntop getaddrinfo)); 
     }
 }
 
@@ -825,8 +825,8 @@
 	($p2,$a2) = unpack_sockaddr_in ($sa2);
     } elsif($this->{'sockfamily'} == AF_INET6()) {
 	# IPv6 addresses
-	($p1,$a1) = unpack_sockaddr_in6 ($sa1);
-	($p2,$a2) = unpack_sockaddr_in6 ($sa2);
+	($p1,$a1) = Socket6::unpack_sockaddr_in6 ($sa1);
+	($p2,$a2) = Socket6::unpack_sockaddr_in6 ($sa2);
     } else {
 	return 0;
     }
@@ -899,7 +899,7 @@
     return undef unless $remote_addr;
 
     if( (defined $ipv6_addr_len) && (length $remote_addr == $ipv6_addr_len)) {
-	($port,$iaddr) = unpack_sockaddr_in6($remote_addr);
+	($port,$iaddr) = Socket6::unpack_sockaddr_in6($remote_addr);
     } else {
 	($port,$iaddr) = unpack_sockaddr_in($remote_addr);
     }
@@ -948,7 +948,7 @@
     return undef unless $remote_addr;
 
     if( (defined $ipv6_addr_len) && (length $remote_addr == $ipv6_addr_len)) {
-	($port,$iaddr) = unpack_sockaddr_in6($remote_addr);
+	($port,$iaddr) = Socket6::unpack_sockaddr_in6($remote_addr);
     } else {
 	($port,$iaddr) = unpack_sockaddr_in($remote_addr);
     }
