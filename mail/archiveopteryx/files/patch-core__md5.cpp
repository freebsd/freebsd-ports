--- ./core/md5.cpp.orig	2014-03-06 13:46:23.918398965 -0600
+++ ./core/md5.cpp	2014-03-06 13:46:30.784414914 -0600
@@ -149,12 +149,9 @@
     }
     swapBytes( in, 14 );
 
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wstrict-aliasing"
     /* Append length in bits and transform. */
     ((uint32 *)in)[14] = bits[0];
     ((uint32 *)in)[15] = bits[1];
-#pragma GCC diagnostic pop
     transform();
     swapBytes( (char *)buf, 4 );
 
