--- generic/bltVector.c.orig	2013-11-18 17:38:24.000000000 +0100
+++ generic/bltVector.c	2013-11-18 17:38:39.000000000 +0100
@@ -370,7 +370,7 @@
     *indexPtr = (int)value;
 cleanup:
     if (string != zStatic) {
-        Blt_Free( string );
+        Blt_Free( (void *)string );
     }
     return result;
 }
