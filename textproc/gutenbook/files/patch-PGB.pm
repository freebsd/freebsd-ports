--- PGB.pm.orig	Thu Dec 21 03:42:50 2000
+++ PGB.pm	Thu Dec 21 03:43:31 2000
@@ -42,8 +42,8 @@
 # $http_url = "http://www.viemeister.com/pub/gutenberg/";
 # $http_url = "http://metalab.unc.edu/pub/docs/books/gutenberg/";
 # $http_url = "http://www.prairienet.org/gutenberg/";
-$zip = "/usr/bin/zip";
-$unzip = "/usr/bin/unzip";
+$zip = "%%LOCALBASE%%/bin/zip";
+$unzip = "%%LOCALBASE%%/bin/unzip";
 
 $index_file = "index";
 $prefs_file = "preferences";
