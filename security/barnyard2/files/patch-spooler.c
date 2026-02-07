--- src/spooler.c.orig	2018-10-06 11:56:32 UTC
+++ src/spooler.c
@@ -1042,7 +1042,7 @@ int spoolerOpenWaldo(Waldo *waldo, uint8
     }
 
     /* check that a waldo file has been specified */
-    if ( waldo->filepath == NULL )
+    if ( waldo->filepath[0] == '\0' )
     {
         return WALDO_FILE_EEXIST;
     }
