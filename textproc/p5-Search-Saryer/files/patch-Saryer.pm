--- Saryer.pm.orig	Mon Jul 11 02:19:01 2005
+++ Saryer.pm	Fri Jun 23 13:38:04 2006
@@ -13,7 +13,7 @@
 
 =head1 SYNOPSIS
 
-  my $saryer = new Search::Saryer(filename->'search.txt');
+  my $saryer = new Search::Saryer(filename=>'search.txt');
   print $saryer->grep($pattern)
 
 =head1 CONSTRUCTOR
