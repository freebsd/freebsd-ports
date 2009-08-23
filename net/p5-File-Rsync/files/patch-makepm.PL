--- makepm.PL.orig	2009-08-22 22:55:32.000000000 -0700
+++ makepm.PL	2009-08-22 22:55:47.000000000 -0700
@@ -10,23 +10,6 @@
 }
 $|=1;
 $RSYNC=&find_rsync;
-print <<'EOT';
-
-File::Rsync needs to know the path to the rsync binary.  This path is encoded
-in the installed module as the default path to rsync (it can be overridden
-at runtime).  Please enter the full path to the rsync program or just hit
-Enter if the guess is correct.  (If you always want the module to depend on
-the $PATH environment variable at runtime, just set the path to 'rsync'
-(this is not recommended)).
-
-EOT
-$RSYNC||='/usr/local/bin/rsync';
-print "Path to rsync [$RSYNC]: ";
-my $ans=<STDIN>;
-chomp $ans;
-$RSYNC=$ans || $RSYNC;
-$RSYNC=~s/\\/\\\\/g;
-$RSYNC=~s/\'/\\\'/g;
 open IN,'config.in' or die "Cannot read config.in: $!\n";
 open OUT,'>config.pm' or die "Cannot write config.pm: $!\n";
 while (<IN>) {
