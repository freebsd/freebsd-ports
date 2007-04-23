--- IkiWiki/Rcs/svn.pm.orig	Sun Jan 28 01:04:48 2007
+++ IkiWiki/Rcs/svn.pm	Mon Apr 16 22:55:29 2007
@@ -176,7 +176,8 @@ sub rcs_recentchanges ($) { #{{{
 		}
 
 		foreach (keys %{$logentry->{paths}}) {
-			next unless /^\/\Q$config{svnpath}\E\/([^ ]+)(?:$|\s)/;
+			next unless ! length $config{svnpath} || 
+			            /^\/\Q$config{svnpath}\E\/([^ ]+)(?:$|\s)/;
 			my $file=$1;
 			my $diffurl=$config{diffurl};
 			$diffurl=~s/\[\[file\]\]/$file/g;
@@ -218,7 +219,8 @@ sub rcs_notify () { #{{{
 	my @changed_pages;
 	foreach my $change (`svnlook changed $config{svnrepo} -r $rev`) {
 		chomp $change;
-		if ($change =~ /^[A-Z]+\s+\Q$config{svnpath}\E\/(.*)/) {
+		if (! length $config{svnpath} || 
+		    $change =~ /^[A-Z]+\s+\Q$config{svnpath}\E\/(.*)/) {
 			push @changed_pages, $1;
 		}
 	}
