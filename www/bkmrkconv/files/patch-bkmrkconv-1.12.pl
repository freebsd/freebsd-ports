--- bkmrkconv-1.12.pl.orig	2016-04-01 15:44:40 UTC
+++ bkmrkconv-1.12.pl
@@ -74,9 +74,10 @@ $outputDir =~ s!/$!!;
 
 chomp(my $oldcwd = `pwd`);
 chdir $outputDir;
-my $rootpage     = &readFile("src/rootpage.html");
-my $linkspage    = &readFile("src/linkspage.html");
-my $contentspage = &readFile("src/contentspage.html") if ($doContents);
+my $shareDir     = '%%PREFIX%%/share/bkmrkconv';
+my $rootpage     = &readFile("$shareDir/src/rootpage.html");
+my $linkspage    = &readFile("$shareDir/src/linkspage.html");
+my $contentspage = &readFile("$shareDir/src/contentspage.html") if ($doContents);
 chdir $oldcwd;
 
 my %root;
