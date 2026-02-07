--- generic/bltTreeViewColumn.c.orig	2013-11-07 18:15:33.000000000 +0100
+++ generic/bltTreeViewColumn.c	2013-11-07 18:16:38.000000000 +0100
@@ -1202,10 +1202,10 @@
     Tcl_Interp *interp;
     TreeViewColumn *columnPtr;
 {
-    if (Blt_ObjConfigModified(columnSpecs, interp, "-background", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, interp, "-background", (char *)NULL)) {
         columnPtr->hasbg = 1;
     }
-    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-titlebackground", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-titlebackground", (char *)NULL)) {
         columnPtr->hasttlbg = 1;
     }
     if (columnPtr->tile != NULL) {
@@ -1213,7 +1213,7 @@
     }
     if (columnPtr->stylePtr == NULL) {
     }
-    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-justify", "-hide", "-weight", "-formatcmd", "-font", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-justify", "-hide", "-weight", "-formatcmd", "-font", (char *)NULL)) {
         Blt_TreeViewMakeStyleDirty(tvPtr);
     }
 }
@@ -1269,20 +1269,20 @@
 	DestroyColumn(tvPtr, columnPtr);
 	return TCL_ERROR;
     }
-    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-background", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-background", (char *)NULL)) {
         columnPtr->hasbg = 1;
     }
-    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-titlebackground", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-titlebackground", (char *)NULL)) {
         columnPtr->hasttlbg = 1;
     }
     if (columnPtr->tile != NULL) {
         Blt_SetTileChangedProc(columnPtr->tile, Blt_TreeViewTileChangedProc, tvPtr);
     }
-    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-*font", "-foreground", "-titleborderwidth", "-titlerelief", "-titleshadow", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-*font", "-foreground", "-titleborderwidth", "-titlerelief", "-titleshadow", (char *)NULL)) {
         Blt_TreeViewMakeStyleDirty(tvPtr);
     }
     ColumnConfigChanges(tvPtr, interp, columnPtr);
-    Blt_ObjConfigModified(columnSpecs, tvPtr->interp, 0);
+    Blt_ObjConfigModified(columnSpecs, tvPtr->interp, (char *)NULL);
     return TCL_OK;
     
 }
@@ -1331,7 +1331,7 @@
 	DestroyColumn(tvPtr, columnPtr);
 	return NULL;
     }
-    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-background", 0)) {
+    if (Blt_ObjConfigModified(columnSpecs, tvPtr->interp, "-background", (char *)NULL)) {
         columnPtr->hasbg = 1;
     }
     if (columnPtr->tile != NULL) {
