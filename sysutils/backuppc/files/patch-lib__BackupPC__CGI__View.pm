--- ./lib/BackupPC/CGI/View.pm.orig	2014-08-30 15:21:07.000000000 +0400
+++ ./lib/BackupPC/CGI/View.pm	2014-08-30 15:21:18.000000000 +0400
@@ -89,7 +89,7 @@
         $file = $bpc->ConfDir() . "/hosts";
         $linkHosts = 1;
     } elsif ( $type eq "docs" ) {
-        $file = $bpc->InstallDir() . "/doc/BackupPC.html";
+        $file = "$Conf{CgiImageDir}/BackupPC.html";
     } elsif ( $host ne "" ) {
         if ( !defined($In{num}) ) {
             # get the latest LOG file
