--- src/pcf/pcfdrivr.c.orig	Thu Mar 18 16:43:18 2004
+++ src/pcf/pcfdrivr.c	Thu Mar 18 16:53:25 2004
@@ -336,9 +336,9 @@
 
 
     FT_TRACE4(( "rec %d - pres %d\n", size->metrics.y_ppem,
-                                      face->root.available_sizes->height ));
+			    face->root.available_sizes->y_ppem >> 6 ));
 
-    if ( size->metrics.y_ppem == face->root.available_sizes->height )
+    if ( size->metrics.y_ppem == face->root.available_sizes->y_ppem >> 6 )
     {
       size->metrics.ascender    = face->accel.fontAscent << 6;
       size->metrics.descender   = face->accel.fontDescent * (-64);
