--- lib/probes/EchoPing.pm.orig	Sun Jan 11 18:06:12 2004
+++ lib/probes/EchoPing.pm	Sun Jan 11 18:06:12 2004
@@ -1,6 +1,6 @@
 package probes::EchoPing;
 
-my $DEFAULTBIN = "/usr/bin/echoping";
+my $DEFAULTBIN = "%%PREFIX%%/bin/echoping";
 
 =head1 NAME
 
@@ -16,7 +16,7 @@
  *** Probes ***
  + EchoPing
 
- binary = /usr/bin/echoping # default value
+ binary = %%PREFIX%%/bin/echoping # default value
 
  *** Targets ***
 
@@ -105,7 +105,7 @@
 
 The location of the echoping binary should probably be a global variable
 instead of a probe-specific one. As things are, every EchoPing -derived probe 
-has to declare it if the default (/usr/bin/echoping) isn't correct.
+has to declare it if the default (%%PREFIX%%/bin/echoping) isn't correct.
 
 =head1 AUTHOR
 
