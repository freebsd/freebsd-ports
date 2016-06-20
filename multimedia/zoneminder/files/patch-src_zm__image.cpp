--- src/zm_image.cpp.orig	2016-06-01 00:41:17 UTC
+++ src/zm_image.cpp
@@ -1619,12 +1619,9 @@ Image *Image::Highlight( unsigned int n_
       for ( unsigned int j = 0; j < n_images; j++ )
       {
         uint8_t *psrc = images[j]->buffer+c;
-
-#ifndef SOLARIS
-        if ( (unsigned)abs((*psrc)-RGB_VAL(ref_colour,c)) >= RGB_VAL(threshold,c) )
-#else
-        if ( (unsigned)std::abs((*psrc)-RGB_VAL(ref_colour,c)) >= RGB_VAL(threshold,c) )
-#endif
+       unsigned int diff = ((*psrc)-RGB_VAL(ref_colour,c)) > 0 ? (*psrc)-RGB_VAL(ref_colour,c) : RGB_VAL(ref_colour,c) - (*psrc);
+        
+       if (diff >= RGB_VAL(threshold,c))
         {
           count++;
         }
