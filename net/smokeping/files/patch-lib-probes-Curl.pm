--- lib/probes/Curl.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/Curl.pm	Sun Jan 11 18:06:12 2004
@@ -1,6 +1,6 @@
 package probes::Curl;
 
-my $DEFAULTBIN = "/usr/bin/curl";
+my $DEFAULTBIN = "%%PREFIX%%/bin/curl";
 
 =head1 NAME
 
@@ -15,7 +15,7 @@
  *** Probes ***
  + Curl
 
- binary = /usr/bin/curl # default value
+ binary = %%PREFIX%%/bin/curl # default value
 
  *** Targets ***
 
