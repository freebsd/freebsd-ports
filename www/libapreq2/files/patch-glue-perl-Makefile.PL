--- glue/perl/Makefile.PL.orig	2006-08-09 04:26:45.000000000 +0000
+++ glue/perl/Makefile.PL	2008-08-25 18:07:08.000000000 +0000
@@ -37,6 +37,50 @@
     read $file, $_[0], -s $file;
 }
 
+sub cmp_tuples {
+    my ($num_a, $num_b) = @_;
+
+    while (@$num_a && @$num_b) {
+        my $cmp = shift @$num_a <=> shift @$num_b;
+        return $cmp if $cmp;
+    }  
+
+    return @$num_a <=> @$num_b;
+}
+
+sub autoconf_foo {
+    my ($config, $re_start, $re_end, $re_match) = @_;
+
+    $$config =~ /^${re_start}APACHE2_INCLUDES${re_end}($re_match)/m or
+        die "Can't find apache include directory";
+    my $apache_includes = $1;
+    $$config =~ /^${re_start}APR_INCLUDES${re_end}($re_match)/m or
+        die "Can't find apache include directory";
+    $apache_includes .= " $1";
+
+    my $apr_libs ="";
+
+    $$config =~ m/^${re_start}APREQ_LIBNAME${re_end}($re_match)/m or
+        die "Can't find apreq libname";
+
+    my $apreq_libname = $1;
+
+    $$config =~ m/^${re_start}PACKAGE_VERSION${re_end}($re_match)/m or
+        die "Can't find package version";
+    my $version = $1;
+
+	## Code around an autoconf 2.60 bug
+	## http://lists.gnu.org/archive/html/bug-autoconf/2006-06/msg00127.html
+	## $ grep @PACKAGE_VERSION config.status-2.59 config.status-2.60 
+	## config.status-2.59:s,@PACKAGE_VERSION@,2.09,;t t
+	## config.status-2.60:s,@PACKAGE_VERSION@,|#_!!_#|2.09,g
+	foreach ($apache_includes, $apreq_libname, $version) {
+	    s/\|#_!!_#\|//g;
+	}
+
+    return ($apache_includes, $apr_libs, $apreq_libname, $version);
+}
+
 my ($apache_includes, $apache_dir, $apr_libs, $apreq_libname, $perl_lib);
 
 if (WIN32) {
@@ -63,31 +107,22 @@
 }
 else {
     slurp my $config => "$base_dir/config.status";
-    $config =~ /^s,\@APACHE2_INCLUDES\@,([^,]+)/m or
-        die "Can't find apache include directory";
-    $apache_includes = $1;
-    $config =~ /^s,\@APR_INCLUDES\@,([^,]+)/m or
-        die "Can't find apache include directory";
-    $apache_includes .= " $1";
-
-#    $config =~ m/^s,\@APR_LDFLAGS\@,([^,]+)/m or
-#        die "Can't find apr ldflags";
-#    $apr_libs = $1;
-
-#    $config =~ m/^s,\@APR_LIBS\@,([^,]+)/m or
-#        die "Can't find apr libraries";
-#    $apr_libs .= " $1";
-
-    $apr_libs ="";
-
-    $config =~ m/^s,\@APREQ_LIBNAME\@,([^,]+)/m or
-        die "Can't find apreq libname";
-    $apreq_libname = $1;
-
-    $config =~ m/^s,\@PACKAGE_VERSION\@,([^,]+)/m or
-        die "Can't find package version";
-    $version = $1;
 
+    $config =~ /GNU Autoconf (\d+\.\d+)/;
+    my $autoconf_ver = $1;
+ 
+    ### XXX: Lord have mercy on us.....
+    if (cmp_tuples([split /\./, $autoconf_ver], [qw(2 61)]) > 0) {
+        ### Autoconf >=2.62 changed the format of the file
+        ### I.E.: S["APACHE2_INCLUDES"]="-I/usr/local/include/apache2"
+        ($apache_includes, $apr_libs, $apreq_libname, $version) = 
+           autoconf_foo(\$config, qr/S\[\"/, qr/\"\]=\"/, qr/[^\"]+/);
+    }
+    else {
+       ### I.E.: s,@APACHE2_INCLUDES@,-I/usr/local/include/apache22,;t t
+       ($apache_includes, $apr_libs, $apreq_libname, $version) = 
+          autoconf_foo(\$config, qr/s,\@/, qr/\@,/, qr/[^,]+/);
+    }
 }
 
 my $apreq_libs = WIN32 ?
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
