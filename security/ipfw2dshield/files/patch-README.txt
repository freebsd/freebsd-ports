--- README.txt.orig	2004-06-01 21:52:15 UTC
+++ README.txt
@@ -21,10 +21,18 @@ This will install the following files:
       /usr/local/bin/ipaddr
       ~/.ipfw2dshield.rc.sample
 
+NNoottee:: For the FreeBSD ports version the sample configuration file is instead
+
+      /usr/local/etc/ipfw2dshield.rc.sample
+
 Copy or rename the sample configuration file to ~~//..iippffww22ddsshhiieelldd..rrcc and edit
 this latter file to fit your local demands. Please read section 2 below for an
 explanation of the configuration entries.
 
+NNoottee:: The FreeBSD ports version does also accept //uussrr//llooccaall//eettcc//iippffww22ddsshhiieelldd..rrcc
+as its configuration file. However, the preference is for ~~//..iippffww22ddsshhiieelldd..rrcc in
+case that both these files exist.
+
 The script creates a stampfile in //vvaarr//ttmmpp where it stores date and time
 information which will be accessed on a subsequent run to prevent multiple
 submission of log records. Hence this file should remain untouched for correct
