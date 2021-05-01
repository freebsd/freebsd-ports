--- lib/Video/DVDRip/FilterList.pm.orig	Fri Sep 22 16:05:34 2006
+++ lib/Video/DVDRip/FilterList.pm	Fri Sep 22 16:06:07 2006
@@ -220,7 +220,7 @@
         "[filterlist] (re)scanning transcode's module path $modpath...\n";
 
     my @filter_names = grep !/^(pv|preview)$/,
-        map {m!/filter_([^/]+)\.so$!} glob("$modpath/filter_*");
+        map {m!/filter_([^/]+)\.so$/!} glob("$modpath/filter_*");
 
     my %filters;
     foreach my $filter_name (@filter_names) {
