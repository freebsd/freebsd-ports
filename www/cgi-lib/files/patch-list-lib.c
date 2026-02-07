--- list-lib.c.orig	Thu May 18 21:10:28 2000
+++ list-lib.c	Tue Jan 15 18:59:31 2002
@@ -79,10 +79,6 @@
 
 	free(List);
 
-	List->ListHead = NULL;
-	List->Count = 0;
-	List->MaxEntries = 0;
-
 }
 
 
