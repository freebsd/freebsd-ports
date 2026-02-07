--- generic/bltTree.h.orig	2013-11-18 17:19:46.000000000 +0100
+++ generic/bltTree.h	2013-11-18 17:23:01.000000000 +0100
@@ -40,7 +40,7 @@
 typedef struct Blt_TreeTagEntryStruct Blt_TreeTagEntry;
 typedef struct Blt_TreeTagTableStruct Blt_TreeTagTable;
 
-typedef char *Blt_TreeKey;
+typedef CONST char *Blt_TreeKey;
 
 /* FindData->order flags. */
 #define TREE_PREORDER		(1<<0)
