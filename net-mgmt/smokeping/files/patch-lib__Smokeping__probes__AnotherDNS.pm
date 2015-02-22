--- lib/Smokeping/probes/AnotherDNS.pm.orig	2014-10-29 09:03:10.000000000 +0100
+++ lib/Smokeping/probes/AnotherDNS.pm	2015-02-12 19:43:50.000000000 +0100
@@ -25,6 +25,8 @@
 use IO::Select;
 use Net::DNS;
 
+use constant PACKETSZ => 512;
+
 sub pod_hash {
 	return {
 		name => <<DOC,
@@ -108,7 +110,7 @@
         $elapsed = tv_interval( $t0, $t1 );
         if ( defined $ready ) {
             my $buf = '';
-            $ready->recv( $buf, 512 );
+            $ready->recv( $buf, PACKETSZ );
 	    my ($recvPacket, $err) = Net::DNS::Packet->new(\$buf);
 	    if (defined $recvPacket) {
 		my $recvHeader = $recvPacket->header();
