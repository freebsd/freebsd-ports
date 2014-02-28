--- ./lib/MailScanner/CustomFunctions/LastSpam.pm.orig	2011-08-20 08:24:49.000000000 -0400
+++ ./lib/MailScanner/CustomFunctions/LastSpam.pm	2014-02-21 04:11:09.000000000 -0500
@@ -32,7 +32,6 @@
 my $Debug = 0; # Set to 1 to enable debug output to STDERR
 #my $tmpfilename = "/tmp/MailScanner.LastSpam.$$.conf"; # Temp MS.conf file
 # Temp MS.conf file
-my($tmpfh, $tmpfilename) = tempfile("MailScanner.LastSpam.XXXXXX", TMPDIR => 1, UNLINK => 0);
 my %modtime = (); # Time domain list magic word file was last changed
 my %filename = (); # Map Config option to magic word file
 my %magicwords = {}; # Map Config option --> domains --> magic words
@@ -550,8 +549,7 @@
 sub SetupRuleset {
   my($opkeyword) = @_;
 
-  my $fh = new FileHandle;
-  $fh->open("> $tmpfilename") or die "$!";
+  my($fh, $tmpfilename) = tempfile("MailScanner.LastSpam.XXXXXX", TMPDIR => 1, UNLINK => 0);
   my $rf = $rulesetfilename{$opkeyword};
   #print STDERR "RF = $rf\n";
   #print STDERR $opkeyword . " = $rf\n";
