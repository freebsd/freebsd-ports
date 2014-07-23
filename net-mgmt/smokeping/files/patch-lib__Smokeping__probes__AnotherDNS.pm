--- lib/Smokeping/probes/AnotherDNS.pm.orig	2012-07-09 09:45:46.000000000 +0000
+++ lib/Smokeping/probes/AnotherDNS.pm	2014-07-22 23:07:45.626343897 +0000
@@ -25,6 +25,8 @@
 use IO::Select;
 use Net::DNS;
 
+use constant PACKETSZ => 512;
+
 sub pod_hash {
 	return {
 		name => <<DOC,
@@ -95,7 +97,7 @@
         $elapsed = tv_interval( $t0, $t1 );
         if ( defined $ready ) {
             my $buf = '';
-            $ready->recv( $buf, &Net::DNS::PACKETSZ );
+            $ready->recv( $buf, PACKETSZ );
 	    my ($recvPacket, $err) = Net::DNS::Packet->new(\$buf);
 	    if (defined $recvPacket) {
 		my $recvHeader = $recvPacket->header();
