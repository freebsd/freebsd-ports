--- save_fits_image.cc.orig	2015-06-11 11:19:38 UTC
+++ save_fits_image.cc
@@ -81,7 +81,7 @@ DEFUN_DLD( save_fits_image, args, nargout,
     else if( args(2).is_scalar_type() )
     {
       double val = args(2).double_value();
-      if( (D_NINT( val ) ==  val) )
+      if( (round( val ) ==  val) )
       {
         if( BYTE_IMG == val )
           bitperpixel = BYTE_IMG;
