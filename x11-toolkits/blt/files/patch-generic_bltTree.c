--- generic/bltTree.c.orig	2013-11-18 17:18:20.000000000 +0100
+++ generic/bltTree.c	2013-11-18 17:23:01.000000000 +0100
@@ -2631,8 +2631,8 @@
 char *
 Blt_TreeNodePath(Node *nodePtr, Tcl_DString *resultPtr)
 {
-    char **nameArr;		/* Used to stack the component names. */
-    char *staticSpace[64];
+    CONST char **nameArr;		/* Used to stack the component names. */
+    CONST char *staticSpace[64];
     int nLevels;
     register int i;
 
@@ -2663,8 +2663,8 @@
 char *
 Blt_TreeNodePathStr(Node *nodePtr, Tcl_DString *resultPtr, char *prefix, char *delim)
 {
-    char **nameArr;		/* Used to stack the component names. */
-    char *staticSpace[64];
+    CONST char **nameArr;		/* Used to stack the component names. */
+    CONST char *staticSpace[64];
     int nLevels;
     register int i;
 
@@ -3083,7 +3083,7 @@
     Blt_HashTable *tablePtr;
     Tcl_Obj *objPtr;
     Value *valuePtr;
-    char *key;
+    CONST char *key;
 
     key = Blt_TreeKeyGet(interp, clientPtr->treeObject,arrayName);
     valuePtr = GetTreeValue(interp, clientPtr, nodePtr, key);
@@ -3143,7 +3143,7 @@
     Blt_HashTable *tablePtr;
     Tcl_Obj *objPtr;
     Value *valuePtr;
-    char *key;
+    CONST char *key;
 
     key = Blt_TreeKeyGet(interp, clientPtr->treeObject,arrayName);
     if ( bltTreeGetValueByKey(interp, clientPtr, nodePtr, key, &valuePtr) != TCL_OK) {
