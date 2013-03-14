--- utils/plrender.c.orig
+++ utils/plrender.c
@@ -834,7 +834,7 @@
     if ( code ) { fprintf( stderr,          \
                       "Unable to read in %s at line %d, bytecount %d\n\
 Bytes requested: %d\n", __FILE__, __LINE__, \
-                      (int) pdfs->bp, (int) 2 * n ); return -1; }
+                      (int) pdfs->bp, (int) 2 * n ); return; }
 
 static void
 get_ncoords( PLFLT *x, PLFLT *y, PLINT n )
@@ -869,7 +869,7 @@
         free( ys );
     }
 
-    return 0;
+    return;
 }
 
 //--------------------------------------------------------------------------
