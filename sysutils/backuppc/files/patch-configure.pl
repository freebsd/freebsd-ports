--- configure.pl.orig	2010-07-31 21:52:58.000000000 +0400
+++ configure.pl	2010-08-16 15:34:17.000000000 +0400
@@ -241,6 +241,7 @@
     $Conf{InstallDir}   ||= $opts{"install-dir"} || "/usr/local/BackupPC";
     $Conf{LogDir}       ||= $opts{"log-dir"}     || "$Conf{TopDir}/log";
 }
+    $Conf{LogDir}       = $opts{"log-dir"};

 #
 # These are the programs whose paths we need to find
