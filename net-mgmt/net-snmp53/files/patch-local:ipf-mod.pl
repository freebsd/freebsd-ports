--- local/ipf-mod.pl.orig	Thu May 29 05:30:19 2003
+++ local/ipf-mod.pl	Thu May 29 05:40:13 2003
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -s
+#!%%PERL%% -s
 ##
 ## IP Filter UCD-SNMP pass module
 ##
@@ -9,10 +9,10 @@
 ## Date: $ Tue Dec  1 10:24:08 EET 1998 $
 ## Version: 1.1a
 
-# Put this file in /usr/local/bin/ipf-mod.pl and then add the following 
+# Put this file in %%PREFIX%%/bin/ipf-mod.pl and then add the following 
 # line to your snmpd.conf file (without the # at the front):
 #
-#   pass .1.3.6.1.4.1.2021.13.2 /usr/local/bin/ipf-mod.pl
+#   pass .1.3.6.1.4.1.2021.13.2 %%PREFIX%%/bin/ipf-mod.pl
 
 # enterprises.ucdavis.ucdExperimental.ipFilter	= .1.3.6.1.4.1.2021.13.2
 # ipfInTable.ipfInEntry.ipfInIndex		integer	= 1.1.1
