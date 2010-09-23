--- configure.pl.orig	2010-07-31 21:52:58.000000000 +0400
+++ configure.pl	2010-08-16 15:34:17.000000000 +0400
@@ -241,6 +241,7 @@
     $Conf{InstallDir}   ||= $opts{"install-dir"} || "/usr/local/BackupPC";
     $Conf{LogDir}       ||= $opts{"log-dir"}     || "$Conf{TopDir}/log";
 }
+    $Conf{LogDir}       = $opts{"log-dir"};

 #
 # These are the programs whose paths we need to find
@@ -521,7 +521,7 @@
 #
 # Create install directories
 #
-foreach my $dir ( qw(bin doc
+foreach my $dir ( qw(bin
 		     lib/BackupPC/CGI
 		     lib/BackupPC/Config
 		     lib/BackupPC/Lang
@@ -689,9 +689,9 @@
 printf("Making Apache configuration file for suid-perl\n");
 InstallFile("httpd/src/BackupPC.conf", "httpd/BackupPC.conf", 0644);
 
-printf("Installing docs in $DestDir$Conf{InstallDir}/doc\n");
+printf("Installing docs in WRKSRC\n");
 foreach my $doc ( qw(BackupPC.pod BackupPC.html) ) {
-    InstallFile("doc/$doc", "$DestDir$Conf{InstallDir}/doc/$doc", 0444);
+    InstallFile("doc/$doc", "./$doc", 0444);
 }
 
 printf("Installing config.pl and hosts in $DestDir$Conf{ConfDir}\n");
