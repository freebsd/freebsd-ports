--- bkmrkconv.pl.orig	Thu Sep 21 00:21:54 2000
+++ bkmrkconv.pl	Wed Mar  7 05:37:20 2001
@@ -70,9 +70,10 @@
 
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
