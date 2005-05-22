--- glue/perl/Makefile.PL	Mon May  2 20:24:29 2005
+++ glue/perl/Makefile.PL	Sat May 21 17:57:39 2005
@@ -443,8 +443,8 @@
     'NAME'      => '$class',
     'VERSION'   => '$version',
     'TYPEMAPS'  => [qw(@$mp2_typemaps $typemap)],
-    'INC'       => "-I$base_dir/glue/perl/xs -I$inc_dir -I$xs_dir $apache_includes",
-    'LIBS'      => "$apreq_libs $apr_libs",
+    'INC'       => "-I$base_dir/glue/perl/xs -I$inc_dir -I$xs_dir $apache_includes -I\\\$(PREFIX)/include/apache2/modules/perl",
+    'LIBS'      => "$apreq_libs $apr_libs -L\\\$(PREFIX)/lib",
 } ;
 $txt .= "'depend'  => $deps,\n" if ($deps) ;
 $txt .= qq{    
