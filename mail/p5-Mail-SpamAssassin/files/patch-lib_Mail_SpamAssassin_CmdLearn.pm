--- lib/Mail/SpamAssassin/CmdLearn.pm.orig	Tue Feb 18 17:29:45 2003
+++ lib/Mail/SpamAssassin/CmdLearn.pm	Thu Feb 27 18:53:49 2003
@@ -24,7 +24,7 @@
   %opt = ();
 
   Getopt::Long::Configure(qw(bundling no_getopt_compat
-                         no_auto_abbrev no_ignore_case));
+                 permute no_auto_abbrev no_ignore_case));
 
   GetOptions(
 	     'spam'				=> sub { $isspam = 1; },
@@ -56,12 +56,12 @@
 	     'file'			=> sub { $opt{'format'} = 'file'; },
 	     'mbox'			=> sub { $opt{'format'} = 'mbox'; },
 
-	     'single'			=> sub {
-		  $opt{'format'} = 'file'; push (@ARGV, '-');
-	      },
+	     'single'			=> sub { $opt{'format'} = 'file'; },
 
 	     '<>'			=> \&target,
   ) or usage(0, "Unknown option!");
+
+  if ($opt{'format'} eq 'file') { push (@ARGV, '-'); }
 
   if (defined $opt{'help'}) { usage(0, "For more information read the manual page"); }
   if (defined $opt{'version'}) {
