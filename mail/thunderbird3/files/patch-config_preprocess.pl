--- config/preprocessor.pl.orig	Wed Aug 13 05:46:33 2003
+++ config/preprocessor.pl	Thu Sep  4 00:42:12 2003
@@ -71,16 +71,40 @@
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
+
 
 sub include {
     my($stack, $filename) = @_;
     my $directory = $stack->{'variables'}->{'DIRECTORY'};
     if ($filename ne '-') {
-        $filename = File::Spec->rel2abs($filename, $directory);
-        my($volume, $path) = File::Spec->splitpath($filename);
-        $directory = File::Spec->catpath($volume, $path, '');
+        $filename = rel2abs($filename, $directory);
+        $directory = File::Spec->catdir(dirname($filename));
     }
     local $stack->{'variables'}->{'DIRECTORY'} = $directory;
     local $stack->{'variables'}->{'FILE'} = $filename;
@@ -374,7 +398,7 @@
     my $stack = shift;
     return if $stack->disabled;
     die "argument expected\n" unless @_;
-    main::include($stack, File::Spec->catpath(File::Spec::Unix->splitpath(@_)));
+    main::include($stack, File::Spec->catfile(dirname(@_), basename(@_)));
 }
 
 sub filter {
