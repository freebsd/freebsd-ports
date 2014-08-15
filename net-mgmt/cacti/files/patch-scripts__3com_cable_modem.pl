--- ./scripts/3com_cable_modem.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/3com_cable_modem.pl	2014-08-11 18:37:08.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 open(PROCESS, "/bin/bash -c 'wget --quiet -O - http://192.168.100.1/cgibin/opcfg | grep \"10.18.18.11\" -c' |");
 $status = <PROCESS>;
