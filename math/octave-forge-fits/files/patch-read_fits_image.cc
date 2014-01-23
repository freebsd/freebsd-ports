--- read_fits_image.cc-orig	2014-01-23 05:25:08.000000000 +0000
+++ read_fits_image.cc	2014-01-23 05:25:45.000000000 +0000
@@ -136,7 +136,7 @@
   }
   //std::cerr << "read_sz: " << read_sz << std::endl;
 
-  #if OCTAVE_API_VERSION_NUMBER >= 45 
+  #if OCTAVE_API_VERSION_NUMBER >= 45 || !defined(OCTAVE_API_VERSION_NUMBER)
     MArray<double> image_data( dims ); // a octace double-type array
   #else
     MArrayN<double> image_data( dims ); // a octave double-type array
