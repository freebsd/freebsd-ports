--- areacode/areacode.c.orig	1997-02-16 10:24:50 UTC
+++ areacode/areacode.c
@@ -352,7 +352,7 @@ static void LoadTable (AreaCodeDesc* Des
 /* Load a part of the table into memory */
 {
     u32 SpaceNeeded = (Desc->Last - Desc->First + 1) * sizeof (u32);
-    Desc->Table = malloc (SpaceNeeded);
+    Desc->Table = (u32*) malloc (SpaceNeeded);
     if (Desc->Table == 0) {
         /* Out of memory. There is no problem with this now since we do
          * not really need the table in core memory (it speeds things up,
