--- build/xsbuilder.pl.orig    Thu Sep 23 17:15:43 2004
+++ build/xsbuilder.pl Thu Sep 23 17:15:26 2004
@@ -309,7 +309,7 @@
     'NAME'      => '$class',
     'VERSION'   => '$version',
     'TYPEMAPS'  => [qw(@$mp2_typemaps $typemap)],
-    'INC'       => "-I$base_dir/glue/perl/xs -I$src_dir -I$xs_dir $apache_includes",
+    'INC'       => "-I$base_dir/glue/perl/xs -I$src_dir -I$xs_dir -I\\\$(PREFIX)/include/apache2/modules/perl $apache_includes",
     'LIBS'      => "$apreq_libs $apr_libs",
 } ;
 $txt .= "'depend'  => $deps,\n" if ($deps) ;
