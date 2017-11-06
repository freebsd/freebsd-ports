--- lib/BackupPC/CGI/View.pm.orig	2015-01-12 00:19:53 UTC
+++ lib/BackupPC/CGI/View.pm
@@ -89,7 +89,7 @@ sub action
         $file = $bpc->ConfDir() . "/hosts";
         $linkHosts = 1;
     } elsif ( $type eq "docs" ) {
-        $file = $bpc->InstallDir() . "/doc/BackupPC.html";
+        $file = "$Conf{CgiImageDir}/BackupPC.html";
     } elsif ( $host ne "" ) {
         if ( !defined($In{num}) ) {
             # get the latest LOG file
