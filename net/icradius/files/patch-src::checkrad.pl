--- src/checkrad.pl.orig	Thu Oct 26 07:35:29 2000
+++ src/checkrad.pl	Wed Jul  4 16:43:11 2001
@@ -35,17 +35,17 @@
 #		$naspass is the location of your NAS admin password file
 #
 
-$prefix		= "/usr/local";
+$prefix		= "%%PREFIX%%";
 $localstatedir	= "/var";
 $logdir		= "${localstatedir}/log";
-$sysconfdir	= "/etc";
+$sysconfdir	= "${prefix}/etc";
 $raddbdir	= "${sysconfdir}/raddb";
 
 $debug		= "";
 #$debug		= "$logdir/checkrad.log";
 
-$snmpget	= "/usr/bin/snmpget";
-$snmpwalk	= "/usr/bin/snmpwalk";
+$snmpget	= "${prefix}/bin/snmpget";
+$snmpwalk	= "${prefix}/bin/snmpwalk";
 $rusers		= "/usr/bin/rusers";
 $naspass	= "$raddbdir/naspasswd";
 
