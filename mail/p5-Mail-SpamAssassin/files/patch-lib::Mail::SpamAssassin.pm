--- lib/Mail/SpamAssassin.pm~	Sun Jan 18 01:07:25 2004
+++ lib/Mail/SpamAssassin.pm	Tue Jan 20 18:27:40 2004
@@ -97,7 +97,8 @@
 # "mss<number>", <number> increasing with every hack.
 @EXTRA_VERSION = qw();
 if (defined $IS_DEVEL_BUILD && $IS_DEVEL_BUILD) {
-  push(@EXTRA_VERSION, ( 'r' . qw{$LastChangedRevision: 6141 $ updated by SVN}[1] ));
+  my @a = qw{$LastChangedRevision: 6141 $ updated by SVN};
+  push(@EXTRA_VERSION, ( 'r' . $a[1] ));
 }
 
 sub Version { join('-', $VERSION, @EXTRA_VERSION) }
