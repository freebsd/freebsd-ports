--- ./lib/BackupPC/CGI/View.pm.orig	2014-09-03 14:15:03.000000000 +0400
+++ ./lib/BackupPC/CGI/View.pm	2014-09-03 14:15:20.000000000 +0400
@@ -102,7 +102,7 @@
         $file = $bpc->ConfDir() . "/hosts";
         $linkHosts = 1;
     } elsif ( $type eq "docs" ) {
-        $file = $bpc->InstallDir() . "/share/doc/BackupPC/BackupPC.html";
+        $file = "$Conf{CgiImageDir}/BackupPC.html";
     } elsif ( $host ne "" ) {
         if ( !defined($In{num}) ) {
             # get the latest LOG file
