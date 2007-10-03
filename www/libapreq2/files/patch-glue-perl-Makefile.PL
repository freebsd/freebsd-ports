--- glue/perl/Makefile.PL.orig	Wed Aug  9 06:26:45 2006
+++ glue/perl/Makefile.PL	Wed Oct  3 11:48:26 2007
@@ -69,6 +69,7 @@
     $config =~ /^s,\@APR_INCLUDES\@,([^,]+)/m or
         die "Can't find apache include directory";
     $apache_includes .= " $1";
+    $apache_includes =~ s,\|\#_!!_\#\|,,g;
 
 #    $config =~ m/^s,\@APR_LDFLAGS\@,([^,]+)/m or
 #        die "Can't find apr ldflags";
@@ -82,12 +83,11 @@
 
     $config =~ m/^s,\@APREQ_LIBNAME\@,([^,]+)/m or
         die "Can't find apreq libname";
-    $apreq_libname = $1;
+    $apreq_libname = $1; $apreq_libname =~ s,^\|\#_!!_\#\|,,;
 
     $config =~ m/^s,\@PACKAGE_VERSION\@,([^,]+)/m or
         die "Can't find package version";
-    $version = $1;
-
+    $version = $1; $version =~ s,^\|\#_!!_\#\|,,;
 }
 
 my $apreq_libs = WIN32 ?
@@ -415,8 +415,8 @@
     'NAME'      => '$class',
     'VERSION'   => '$version',
     'TYPEMAPS'  => [qw(@$mp2_typemaps $typemap)],
-    'INC'       => "-I$base_dir/glue/perl/xs -I$inc_dir -I$xs_dir $apache_includes",
-    'LIBS'      => "$apreq_libs $apr_libs",
+    'INC'       => "-I$base_dir/glue/perl/xs -I$inc_dir -I$xs_dir $apache_includes -I\\\$(PREFIX)/%%APACHEINCLUDEDIR%%/modules/perl",
+    'LIBS'      => "$apreq_libs $apr_libs -L\\\$(PREFIX)/lib",
 } ;
 $txt .= "'depend'  => $deps,\n" if ($deps) ;
 $txt .= qq{    
