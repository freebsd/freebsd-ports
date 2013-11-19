--- generic/bltTreeView.c.orig	2013-11-07 18:13:38.000000000 +0100
+++ generic/bltTreeView.c	2013-11-07 18:14:17.000000000 +0100
@@ -2120,7 +2120,7 @@
         }
     }
     tvPtr->flags |= (TV_LAYOUT | TV_DIRTY | TV_RESORT);
-    Blt_ObjConfigModified(bltTreeViewEntrySpecs, tvPtr->interp, 0);
+    Blt_ObjConfigModified(bltTreeViewEntrySpecs, tvPtr->interp, (char *)NULL);
     return TCL_OK;
 }
 
@@ -4110,7 +4110,7 @@
 	(char *)NULL)) {
 	Blt_TreeViewUpdateColumnGCs(tvPtr, &tvPtr->treeColumn);
     }
-    Blt_ObjConfigModified(bltTreeViewSpecs, interp, 0);
+    Blt_ObjConfigModified(bltTreeViewSpecs, interp, (char *)NULL);
     Blt_TreeViewEventuallyRedraw(tvPtr);
     return TCL_OK;
 }
