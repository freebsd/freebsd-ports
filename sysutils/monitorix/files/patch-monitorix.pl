--- ./monitorix.pl.orig	2010-06-21 10:54:38.000000000 +0200
+++ ./monitorix.pl	2010-08-15 20:20:34.000000000 +0200
@@ -733,20 +733,25 @@
 	if($ENABLE_CROND_MAIL ne "Y") {
 		$mailto = "MAILTO=\"\"";
 	}
-	open(OCRON, "> $O_CRON");
-	print OCRON <<EOF;
-# @(#) Fibranet NSP, SL
-# Copyright (C) 2005-2010 by Jordi Sanfeliu <jordi\@fibranet.cat>
-#
-PATH=/sbin:/bin:/usr/sbin:/usr/bin
-$mailto
+# FreeBSD: 
+# The crontab replacment was removed for the port,
+# we can not risc the damage of existing crontabs!
+	print <<EOF;
+ ===========================================================================
+ To prevent replacement of the root crontab this 
+ function is disabled in the FreeBSD port!
 
-* * * * * $crontabuser $PATH_BIN{$OSTYPE} update
-00 00 * * * $crontabuser $PATH_BIN{$OSTYPE} collect
-01 00 1 * * $crontabuser $PATH_BIN{$OSTYPE} report
+ Please place the following entries in the root crontab
+ or /etc/crontab manually!
+
+  $mailto
+  *  *  * * * $PATH_BIN{$OSTYPE} update
+  00 00 * * * $PATH_BIN{$OSTYPE} collect
+  01 00 1 * * $PATH_BIN{$OSTYPE} report
+
+ ===========================================================================
 
 EOF
-	close(OCRON);
 
 	if($THEME_COLOR eq "black") {
 		$bgcolor = "#000000";
@@ -1053,7 +1058,24 @@
 		unlink($PATH_CRON{$OSTYPE});
 		unlink($PATH_CRON{$OSTYPE} . ".sh");	# old name
 	} elsif($OSTYPE eq "FreeBSD") {
-		system("echo 'y' | crontab -u root -r");
+# FreeBSD: 
+# The crontab replacment was removed for the port,
+# we can not risc the damage of existing crontabs!
+	print <<EOF;
+
+ ========================================================================
+ To prevent deletion of the root crontab this function has been disabled!
+
+ Please remove the following entries from the root crontab or from
+ /etc/crontab manually!
+
+  *  *  * * * $PATH_BIN{$OSTYPE} update
+  00 00 * * * $PATH_BIN{$OSTYPE} collect
+  01 00 1 * * $PATH_BIN{$OSTYPE} report
+
+ ========================================================================
+
+EOF
 	}
 }
 
