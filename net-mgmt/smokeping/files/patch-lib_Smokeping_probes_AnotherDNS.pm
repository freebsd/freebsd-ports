--- lib/Smokeping/probes/AnotherDNS.pm.orig	2018-02-02 21:14:55 UTC
+++ lib/Smokeping/probes/AnotherDNS.pm
@@ -25,6 +25,8 @@ use IO::Socket;
 use IO::Select;
 use Net::DNS;
 
+use constant PACKETSZ => 512;
+
 sub pod_hash {
 	return {
 		name => <<DOC,
@@ -111,7 +113,7 @@ sub pingone ($) {
         $elapsed = tv_interval( $t0, $t1 );
         if ( defined $ready ) {
             my $buf = '';
-            $ready->recv( $buf, 512 );
+            $ready->recv( $buf, PACKETSZ );
 	    my ($recvPacket, $err) = Net::DNS::Packet->new(\$buf);
 	    if (defined $recvPacket) {
 		my $recvHeader = $recvPacket->header();
