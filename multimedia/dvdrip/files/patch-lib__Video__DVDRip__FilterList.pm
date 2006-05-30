--- lib/Video/DVDRip/FilterList.pm.orig	Sat Jul 23 03:00:00 2005
+++ lib/Video/DVDRip/FilterList.pm	Sat Mar 25 18:09:24 2006
@@ -211,7 +211,7 @@
 	print STDERR "[filterlist] (re)scanning transcode's module path $modpath...\n";
 	
 	my @filter_names = grep !/^(pv|preview)$/,
-			   map  {m!/filter_([^/]+)\.so$!}
+			   map  {m!/filter_([^/]+)\.so$/!}
 			   glob ("$modpath/filter_*");
 
 	my %filters;
