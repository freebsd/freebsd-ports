--- Kernel/System/Loader.pm.orig	2010-12-02 18:20:40.000000000 +0000
+++ Kernel/System/Loader.pm	2010-12-02 18:21:30.000000000 +0000
@@ -19,8 +19,8 @@
 
 use Kernel::System::CacheInternal;
 
-use CSS::Minifier qw();
-use JavaScript::Minifier qw();
+use CSS::Minifier::XS qw();
+use JavaScript::Minifier::XS qw();
 
 =head1 NAME
 
@@ -361,7 +361,7 @@
         return;
     }
 
-    my $Result = CSS::Minifier::minify( input => $Param{Code} );
+    my $Result = CSS::Minifier::XS::minify( $Param{Code} );
 
     # a few optimizations can be made for the minified CSS that CSS::Minifier doesn't yet do
 
@@ -408,7 +408,7 @@
         return;
     }
 
-    return JavaScript::Minifier::minify( input => $Param{Code} );
+    return JavaScript::Minifier::XS::minify( $Param{Code} );
 }
 
 =item CacheDelete()
