--- routingtable.cgi.orig	Thu Dec 14 00:56:50 2006
+++ routingtable.cgi	Thu Dec 14 00:57:29 2006
@@ -1,4 +1,4 @@
-#!/usr/local/bin/perl -w
+#!%%LOCALBASE%%/bin/speedy -- -M20 -t3600 -gnone -r500
 # CHANGE ABOVE PATH TO MATCH YOUR PERL LOCATION! You may remove the -w
 ##############################################################################.
 # routingtable.cgi : Version v1.5
@@ -21,7 +21,7 @@
 ##############################################################################.
 use strict;
 use CGI;        # for CGI
-#use Net::SNMP; # ActivePerl users may need this uncommented
+use Net::SNMP; # ActivePerl users may need this uncommented
 ##############################################################################.
 my ($VERSION) = "v1.5";
 my ($APPURL ) = "http://www.steveshipway.org/software/";
