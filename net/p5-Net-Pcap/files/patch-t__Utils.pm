--- t/Utils.pm.orig	2012-04-05 17:39:45 UTC
+++ t/Utils.pm
@@ -73,7 +73,7 @@
 my @devs = Net::Pcap::findalldevs(\%devs, \$err);
 
 # filter out unusable devices
-@devs = grep { $_ ne "lo" and $_ ne "lo0" and $_ !~ /GenericDialupAdapter/ } @devs;
+@devs = grep { $_ ne "lo" and $_ ne "lo0" and $_ !~ /GenericDialupAdapter/ and $_ !~ /^usbus/ } @devs;
 
 # check if the user has specified a prefered device to use for tests
 if (open(PREF, "device.txt")) {
