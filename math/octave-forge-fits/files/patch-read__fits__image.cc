--- read_fits_image.cc.orig	2015-06-11 11:19:38 UTC
+++ read_fits_image.cc
@@ -194,7 +194,7 @@ static bool any_bad_argument( const octave_value_list&
       return true;
     }
     double val = args(1).double_value();
-    if( (D_NINT( val ) !=  val) || (val < 0) )
+    if( (round( val ) !=  val) || (val < 0) )
     {
       error( "read_fits_image: second argument must be a non-negative scalar integer value" );
       return true;
