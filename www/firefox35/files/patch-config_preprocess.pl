$FreeBSD$

--- config/preprocessor.pl.orig	Tue Sep  2 17:53:55 2003
+++ config/preprocessor.pl	Sat Oct 18 23:00:35 2003
@@ -73,16 +73,39 @@
 ########################################################################
 
 package main;
-use File::Spec 0.8;
+use File::Spec;
 use File::Spec::Unix; # on all platforms, because the #include syntax is unix-based
+use File::Basename;
+use Cwd;
+
+# This code is taken from File::Spec::Unix 0.8.
+sub rel2abs {
+    my ($path, $base) = @_;
+
+    if ( ! File::Spec->file_name_is_absolute( $path ) ) {
+	if ( !defined( $base ) || $base eq '' ) {
+	    $base = cwd() ;
+	}
+	elsif ( ! File::Spec->file_name_is_absolute( $base ) ) {
+	    $base = rel2abs( $base );
+	}
+	else {
+	    $base = File::Spec->canonpath( $base );
+	}
+
+	$path = File::Spec->catdir( $base, $path );
+    }
+
+    return File::Spec->canonpath( $path );
+}
+# End code from File::Spec::Unix
 
 sub include {
     my($stack, $filename) = @_;
     my $directory = $stack->{'variables'}->{'DIRECTORY'};
     if ($filename ne '-') {
-        $filename = File::Spec->rel2abs($filename, $directory);
-        my($volume, $path) = File::Spec->splitpath($filename);
-        $directory = File::Spec->catpath($volume, $path, '');
+        $filename = rel2abs($filename, $directory);
+        $directory = File::Spec->catdir(File::Basename::dirname($filename));
     }
     local $stack->{'variables'}->{'DIRECTORY'} = $directory;
     local $stack->{'variables'}->{'FILE'} = $filename;
@@ -376,7 +399,7 @@
     my $stack = shift;
     return if $stack->disabled;
     die "argument expected\n" unless @_;
-    main::include($stack, File::Spec->catpath(File::Spec::Unix->splitpath(@_)));
+    main::include($stack, File::Spec->catfile(File::Basename::dirname(@_), File::Basename::basename(@_)));
 }
 
 sub filter {
