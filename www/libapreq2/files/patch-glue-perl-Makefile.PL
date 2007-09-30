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
@@ -417,4 +417,4 @@
     'TYPEMAPS'  => [qw(@$mp2_typemaps $typemap)],
-    'INC'       => "-I$base_dir/glue/perl/xs -I$inc_dir -I$xs_dir $apache_includes",
-    'LIBS'      => "$apreq_libs $apr_libs",
+    'INC'       => "-I$base_dir/glue/perl/xs -I$inc_dir -I$xs_dir $apache_includes -I\\\$(PREFIX)/include/apache2/modules/perl",
+    'LIBS'      => "$apreq_libs $apr_libs -L\\\$(PREFIX)/lib",
 } ;
