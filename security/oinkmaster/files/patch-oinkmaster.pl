--- oinkmaster.pl.orig	Wed Jan 29 00:33:49 2003
+++ oinkmaster.pl	Wed Jan 29 00:35:50 2003
@@ -20,7 +20,7 @@
 sub clean_exit;
 
 my $version           = 'Oinkmaster v0.6 by Andreas Östling <andreaso@it.su.se>';
-my $config_file       = "./oinkmaster.conf";
+my $config_file       = "%%PREFIX%%/etc/oinkmaster.conf";
 my $tmpdir            = "/tmp/oinkmaster.$$";
 my $outfile           = "snortrules.tar.gz";
 my $verbose           = 0;
