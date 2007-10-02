--- glue/perl/Makefile.PL.orig	2006-08-08 21:26:45.000000000 -0700
+++ glue/perl/Makefile.PL	2007-09-22 20:12:05.000000000 -0700
@@ -71,2 +71,3 @@
     $apache_includes .= " $1";
+    $apache_includes =~ s,\|\#_!!_\#\|,,g;
 
@@ -84,3 +85,3 @@
         die "Can't find apreq libname";
-    $apreq_libname = $1;
+    $apreq_libname = $1; $apreq_libname =~ s,^\|\#_!!_\#\|,,;
 
@@ -88,4 +89,3 @@
         die "Can't find package version";
-    $version = $1;
-
+    $version = $1; $version =~ s,^\|\#_!!_\#\|,,;
 }
