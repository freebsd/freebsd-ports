--- reports/frequentcheck.sh.orig	2007-10-12 04:42:16.000000000 +0400
+++ reports/frequentcheck.sh	2007-10-12 04:42:45.000000000 +0400
@@ -43,10 +43,10 @@
 
 PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin
 
-PATFILE=$OFWTKPATH/etc/frequentcheck.ignore
-ALERTFILE=$OFWTKPATH/etc/securityalerts.ignore
-WARNFILE=$OFWTKPATH/etc/securitywarnings.ignore
-ERRFILE=$OFWTKPATH/etc/syserr.ignore
+PATFILE=$OFWTKPATH/etc/openfwtk/frequentcheck.ignore
+ALERTFILE=$OFWTKPATH/etc/openfwtk/securityalerts.ignore
+WARNFILE=$OFWTKPATH/etc/openfwtk/securitywarnings.ignore
+ERRFILE=$OFWTKPATH/etc/openfwtk/syserr.ignore
 
 # Set the flag variables
 FOUND=0
