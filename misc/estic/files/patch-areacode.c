--- areacode/areacode.c.orig	1997-02-16 11:24:50.000000000 +0100
+++ areacode/areacode.c	2014-03-31 19:07:27.000000000 +0200
@@ -352,7 +352,7 @@
 /* Load a part of the table into memory */
 {
     u32 SpaceNeeded = (Desc->Last - Desc->First + 1) * sizeof (u32);
-    Desc->Table = malloc (SpaceNeeded);
+    Desc->Table = (u32*) malloc (SpaceNeeded);
     if (Desc->Table == 0) {
         /* Out of memory. There is no problem with this now since we do
          * not really need the table in core memory (it speeds things up,
