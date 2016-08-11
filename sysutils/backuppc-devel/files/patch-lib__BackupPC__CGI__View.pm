--- lib/BackupPC/CGI/View.pm.orig	2013-12-01 20:58:20 UTC
+++ lib/BackupPC/CGI/View.pm
@@ -102,7 +102,7 @@ sub action
         $file = $bpc->ConfDir() . "/hosts";
         $linkHosts = 1;
     } elsif ( $type eq "docs" ) {
-        $file = $bpc->InstallDir() . "/share/doc/BackupPC/BackupPC.html";
+        $file = "$Conf{CgiImageDir}/BackupPC.html";
     } elsif ( $host ne "" ) {
         if ( !defined($In{num}) ) {
             # get the latest LOG file
@@ -148,6 +148,10 @@ sub action
 		    }
 		    $s =~ s/[\n\r]+//g;
 		    if ( $s =~ /smb: \\>/
+			    || $s =~ /^tar:\d+\s/
+			    || $s =~ /^  NTLMSSP_/
+			    || $s =~ /^GENSEC backend /
+			    || $s =~ /^doing parameter /
 			    || $s =~ /^\s*(\d+) \(\s*\d+\.\d kb\/s\) (.*)$/
 			    || $s =~ /^tar: dumped \d+ files/
 			    || $s =~ /^\s*added interface/i
