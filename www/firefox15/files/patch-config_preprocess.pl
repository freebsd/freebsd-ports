--- config/preprocessor.pl.orig	Wed Jun 18 17:40:48 2003
+++ config/preprocessor.pl	Wed Jun 18 18:55:28 2003
@@ -71,15 +71,39 @@
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
     if ($filename ne '-') {
-        $filename = File::Spec->rel2abs($filename, $stack->{'variables'}->{'DIRECTORY'});
-        my($volume, $directory) = File::Spec->splitpath($filename);
-        local $stack->{'variables'}->{'DIRECTORY'} = File::Spec->catpath($volume, $directory, '');
+        $filename = rel2abs($filename, $stack->{'variables'}->{'DIRECTORY'});
+	my ($directory) = dirname($filename);
+        local $stack->{'variables'}->{'DIRECTORY'} = File::Spec->catdir($directory);
     }
     local $stack->{'variables'}->{'FILE'} = $filename;
     local $stack->{'variables'}->{'LINE'} = 0;
@@ -372,7 +396,7 @@
     my $stack = shift;
     return if $stack->disabled;
     die "argument expected\n" unless @_;
-    main::include($stack, File::Spec->catpath(File::Spec::Unix->splitpath(@_)));
+    main::include($stack, File::Spec->catfile(dirname(@_), basename(@_)));
 }
 
 sub filter {
