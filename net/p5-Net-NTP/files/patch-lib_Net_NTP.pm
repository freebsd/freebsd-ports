--- lib/Net/NTP.pm.orig	2017-03-30 18:32:06 UTC
+++ lib/Net/NTP.pm
@@ -179,6 +179,7 @@ sub get_ntp_response {
         alarm(0);
     };
     alarm 0;
+    die $@ if $@;
 
     my $rectime = time; # T4
     my $pkt = Net::NTP::Packet->decode($data, $xmttime, $rectime);
