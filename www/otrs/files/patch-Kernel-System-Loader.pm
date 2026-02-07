--- Kernel/System/Loader.pm.orig	2015-05-11 14:29:06 UTC
+++ Kernel/System/Loader.pm
@@ -12,8 +12,8 @@ package Kernel::System::Loader;
 use strict;
 use warnings;
 
-use CSS::Minifier qw();
-use JavaScript::Minifier qw();
+use CSS::Minifier::XS qw();
+use JavaScript::Minifier::XS qw();
 
 our @ObjectDependencies = (
     'Kernel::Config',
@@ -336,7 +336,7 @@ sub MinifyCSS {
         return;
     }
 
-    my $Result = CSS::Minifier::minify( input => $Param{Code} );
+    my $Result = CSS::Minifier::XS::minify( $Param{Code} );
 
     # a few optimizations can be made for the minified CSS that CSS::Minifier doesn't yet do
 
@@ -383,7 +383,7 @@ sub MinifyJavaScript {
         return;
     }
 
-    return JavaScript::Minifier::minify( input => $Param{Code} );
+    return JavaScript::Minifier::XS::minify( $Param{Code} );
 }
 
 =item CacheGenerate()
