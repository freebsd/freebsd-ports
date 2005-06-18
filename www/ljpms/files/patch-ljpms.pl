--- ljpms.pl.orig	Mon Jan  3 15:19:08 2005
+++ ljpms.pl	Sat Jun 18 21:59:45 2005
@@ -84,7 +84,7 @@
 exit(usage('invalidmode')) unless ($modes{$mode} || $mode =~ /^\d+$/);
 exit (usage('noexport')) unless -d LOCALDIR . "$suser/export";
 
-if ($suser ne $user) { # post to someone else's journal
+if ($suser ne $user || $mode eq 'restore') { # post to someone else's journal
 	exit usage('invalidmode') if ($mode eq 'delete');
 	exit usage('invalidmode') if ($mode =~ /^\d+$/);
 	print "posting ${suser}'s backdated entries to ${user}'s journal\n";
