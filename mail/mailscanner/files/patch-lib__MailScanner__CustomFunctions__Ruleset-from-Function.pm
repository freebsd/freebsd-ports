--- ./lib/MailScanner/CustomFunctions/Ruleset-from-Function.pm.orig	2011-08-20 08:25:42.000000000 -0400
+++ ./lib/MailScanner/CustomFunctions/Ruleset-from-Function.pm	2014-02-21 04:16:55.000000000 -0500
@@ -31,7 +31,6 @@
 
 my $Debug = 0; # Set to 1 to enable debug output to STDERR
 #my $tmpfilename = "/tmp/MailScanner.$$.conf"; # Temp MS.conf file
-my($tmpfh, $tmpfilename) = tempfile("MailScanner.XXXXXX", TMPDIR => 1, UNLINK => 0);
 
 
 
@@ -60,8 +59,7 @@
   my $option = 'virusscanning'; # External (MailScanner.conf-version)
 
   # Make the temporary 1-line MailScanner.conf file, use it and delete it
-  my $fh = new FileHandle;
-  $fh->open("> $tmpfilename") or die "$!";
+  my($fh, $tmpfilename) = tempfile("MailScanner.XXXXXX", TMPDIR => 1, UNLINK => 0);
   print $fh $option . " = $ruleset\n";
   $fh->close;
 
