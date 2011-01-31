--- lib/SNMP_Session.pm.orig	2011-01-31 14:10:12.000000000 +0600
+++ lib/SNMP_Session.pm	2011-01-31 14:11:20.000000000 +0600
@@ -146,7 +146,7 @@
 
     if (eval {local $SIG{__DIE__};require Socket6;} &&
        eval {local $SIG{__DIE__};require IO::Socket::INET6; IO::Socket::INET6->VERSION("1.26");}) {
-	import Socket6;
+       	Socket6->import(qw(pack_sockaddr_in6 inet_pton getaddrinfo));
 	$ipv6_addr_len = length(pack_sockaddr_in6(161, inet_pton(AF_INET6(), "::1")));
 	$SNMP_Session::ipv6available = 1;
     }
@@ -601,7 +601,7 @@
 BEGIN {
     if($SNMP_Session::ipv6available) {
 	import IO::Socket::INET6;
-	import Socket6;
+	Socket6->import(qw(pack_sockaddr_in6 inet_pton getaddrinfo)); 
     }
 }
 

