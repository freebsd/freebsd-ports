--- makepm.PL.orig	Sun May 20 10:23:34 2001
+++ makepm.PL	Sun May 20 10:30:05 2001
@@ -1,32 +1,8 @@
 # makepm.PL -- Builds Rsync.pm from Rsync.in.  -*- perl -*-
-sub find_rsync {
-   my @dirs = map { s/^$/./; $_ } split (':', $ENV{PATH});
-   push (@dirs, qw(/usr/local/bin /usr/bin /opt/bin));
-   for my $dir (@dirs) {
-      next unless -d $dir;
-      next unless -x "$dir/rsync";
-      return "$dir/rsync";
-   }
-}
 $|=1;
-$RSYNC=&find_rsync;
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
+$PREFIX=@ARGV[0];
+$RSYNC=$PREFIX . "/bin/rsync";
+print "Path to rsync [$RSYNC]";
 open IN,'Config.in' or die "Cannot read Config.in: $!\n";
 open OUT,'>Config.pm' or die "Cannot write Config.pm: $!\n";
 while (<IN>) {
