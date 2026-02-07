--- generic/bltTreeCmd.c.orig	2010-12-26 22:03:13.000000000 +0100
+++ generic/bltTreeCmd.c	2013-11-18 17:38:10.000000000 +0100
@@ -1544,8 +1544,8 @@
     Tcl_DString *resultPtr,
     int lastOnly)
 {
-    char **nameArr;		/* Used to stack the component names. */
-    char *staticSpace[64];
+    CONST char **nameArr;		/* Used to stack the component names. */
+    CONST char *staticSpace[64];
     register int i;
     int nLevels;
 
@@ -2189,11 +2189,11 @@
 }
 
 static int
-ComparePatternList(Blt_List patternList, char *string, int nocase)
+ComparePatternList(Blt_List patternList, CONST char *string, int nocase)
 {
     Blt_ListNode node;
     int result, type;
-    char *pattern;
+    char *pattern, *s;
 
     result = FALSE;
     for (node = Blt_ListFirstNode(patternList); node != NULL; 
@@ -2217,12 +2217,14 @@
 		    
 	case PATTERN_REGEXP:
             if (nocase) {
-                string = Blt_Strdup(string);
-                strtolower(string);
+                s = Blt_Strdup(string);
+                strtolower(s);
+            } else {
+                s = (char *)string;
             }
-	    result = (Tcl_RegExpMatch((Tcl_Interp *)NULL, string, pattern) == 1); 
+	    result = (Tcl_RegExpMatch((Tcl_Interp *)NULL, s, pattern) == 1); 
             if (nocase) {
-                Blt_Free(string);
+                Blt_Free(s);
             }
 	    break;
 	}
@@ -2231,10 +2233,10 @@
 }
 
 static int
-ComparePattern(FindData *findData, char *string)
+ComparePattern(FindData *findData, CONST char *string)
 {
     int result, type, nocase;
-    char *pattern;
+    char *pattern, *s;
     int objc, i;
     Tcl_Obj **objv, *obj;
 
@@ -2258,14 +2260,16 @@
 		    
 	case PATTERN_REGEXP:
             if (nocase) {
-                string = Blt_Strdup(string);
-                strtolower(string);
+                s = Blt_Strdup(string);
+                strtolower(s);
+            } else {
+                s = (char *)string;
             }
-            obj = Tcl_NewStringObj(string, -1);
+            obj = Tcl_NewStringObj(s, -1);
 	    result = (Tcl_RegExpMatchObj((Tcl_Interp *)NULL, obj, findData->name) == 1); 
 	    Tcl_DecrRefCount(obj);
             if (nocase) {
-	       Blt_Free(string);
+	       Blt_Free(s);
             }
 	    break;
 	case PATTERN_INLIST:
@@ -2316,7 +2320,7 @@
     /* Append the widget name and the node .t 0 */
     for (last = p = command; *p != '\0'; p++) {
 	if (*p == '%') {
-	    char *string;
+	    CONST char *string;
 	    char buf[3];
 
 	    if (p > last) {
@@ -2454,7 +2458,7 @@
     int result, invert, cntf;
     unsigned int inode;
     int strict, isnull;
-    char *curValue = NULL;
+    CONST char *curValue = NULL;
     Tcl_Obj *curObj = NULL, *resObjPtr = NULL;
     
     isnull = ((dataPtr->flags&MATCH_ISNULL) != 0);
@@ -2532,7 +2536,7 @@
 	    key != NULL; key = Blt_TreeNextKey(cmdPtr->tree, &cursor)) {
              
             curObj = NULL;
-	    result = ComparePatternList(dataPtr->keyList, key, 0);
+	    result = ComparePatternList(dataPtr->keyList, (char *)key, 0);
 	    if (!result) {
 		continue;
 	    }
@@ -2771,7 +2775,7 @@
 	    break;
 	}
     } else if (dataPtr->patternList != NULL) {	    
-	char *string;
+	CONST char *string;
 
 	if (dataPtr->flags & MATCH_PATHNAME) {
 	    string = GetNodePath(cmdPtr, Blt_TreeRootNode(cmdPtr->tree),
@@ -3340,7 +3344,7 @@
     Blt_TreeNode parent)	/* New parent for the copied node. */
 {
     Blt_TreeNode newNode;	/* Newly created copy. */
-    char *label;
+    CONST char *label;
     int isNew = 0;
 
     newNode = NULL;
@@ -7829,7 +7833,7 @@
 CompareNodes(Blt_TreeNode *n1Ptr, Blt_TreeNode *n2Ptr)
 {
     TreeCmd *cmdPtr = sortData.cmdPtr;
-    char *s1, *s2;
+    CONST char *s1, *s2;
     int result;
     Tcl_DString dString1, dString2;
 
@@ -8894,6 +8898,7 @@
  * Obj Callback for sqlload.
  *
  */
+#if 0
 static int SqlCallbackObj(SqlData *sqlPtr, int argc, Tcl_Obj **objv, Tcl_Obj **azColName)
 {
     int i, j, rid, lid, n, tcid, vobjc, tobjc;
@@ -9122,6 +9127,7 @@
     return 1;
 }
 #endif
+#endif
 
 #ifndef OMIT_SQLITE3_LOAD
 /* #include <sqlite3.h> */
