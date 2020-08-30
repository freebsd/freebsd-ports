--- lib/SNMP_Session.pm.orig	2008-11-21 05:25:17 UTC
+++ lib/SNMP_Session.pm
@@ -146,8 +146,8 @@ BEGIN {
 
     if (eval {local $SIG{__DIE__};require Socket6;} &&
        eval {local $SIG{__DIE__};require IO::Socket::INET6; IO::Socket::INET6->VERSION("1.26");}) {
-	import Socket6;
-	$ipv6_addr_len = length(pack_sockaddr_in6(161, inet_pton(AF_INET6(), "::1")));
+       	Socket6->import(qw(inet_pton inet_ntop getaddrinfo));
+	$ipv6_addr_len = length(Socket6::pack_sockaddr_in6(161, inet_pton(AF_INET6(), "::1")));
 	$SNMP_Session::ipv6available = 1;
     }
     eval 'local $SIG{__DIE__};local $SIG{__WARN__};$dont_wait_flags = MSG_DONTWAIT();';
@@ -194,8 +194,11 @@ sub set_retries {
 }
 sub set_backoff {
     my ($session, $backoff) = @_;
+    my ($_good, $_warn);
+
+    { local $SIG{__WARN__} = sub { $_warn = $_[0] }; $_good = $backoff >= 1.0; }
     croak ("backoff ($backoff) must be a number >= 1.0")
-	unless $backoff == int ($backoff) && $backoff >= 1.0;
+	unless $_good && !$_warn;
     $session->{'backoff'} = $backoff; 
 }
 
@@ -549,7 +552,7 @@ sub pretty_address {
     # complaining about AF_INET6 when Socket6 is not available
 
     if( (defined $ipv6_addr_len) && (length $addr == $ipv6_addr_len)) {
-	($port,$addrunpack) = unpack_sockaddr_in6 ($addr);
+	($port,$addrunpack) = Socket6::unpack_sockaddr_in6 ($addr);
 	$addrstr = inet_ntop (AF_INET6(), $addrunpack);
     } else {
 	($port,$addrunpack) = unpack_sockaddr_in ($addr);
@@ -605,7 +608,7 @@ use Carp;
 BEGIN {
     if($SNMP_Session::ipv6available) {
 	import IO::Socket::INET6;
-	import Socket6;
+	Socket6->import(qw(inet_pton inet_ntop getaddrinfo)); 
     }
 }
 
@@ -825,8 +828,8 @@ sub sa_equal_p ($$$) {
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
@@ -899,7 +902,7 @@ sub receive_trap {
     return undef unless $remote_addr;
 
     if( (defined $ipv6_addr_len) && (length $remote_addr == $ipv6_addr_len)) {
-	($port,$iaddr) = unpack_sockaddr_in6($remote_addr);
+	($port,$iaddr) = Socket6::unpack_sockaddr_in6($remote_addr);
     } else {
 	($port,$iaddr) = unpack_sockaddr_in($remote_addr);
     }
@@ -948,7 +951,7 @@ sub receive_request {
     return undef unless $remote_addr;
 
     if( (defined $ipv6_addr_len) && (length $remote_addr == $ipv6_addr_len)) {
-	($port,$iaddr) = unpack_sockaddr_in6($remote_addr);
+	($port,$iaddr) = Socket6::unpack_sockaddr_in6($remote_addr);
     } else {
 	($port,$iaddr) = unpack_sockaddr_in($remote_addr);
     }
