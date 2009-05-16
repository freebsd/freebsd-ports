--- glue/perl/Makefile.PL.orig	2006-08-09 04:26:45.000000000 +0000
+++ glue/perl/Makefile.PL	2008-08-25 18:07:08.000000000 +0000
@@ -415,8 +450,8 @@
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
