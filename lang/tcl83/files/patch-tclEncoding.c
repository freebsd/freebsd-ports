--- ../generic/tclEncoding.c.orig	Thu Apr  5 13:28:52 2001
+++ ../generic/tclEncoding.c	Thu Apr 10 00:49:34 2003
@@ -310,19 +310,19 @@
 {
     Tcl_HashSearch search;
     Tcl_HashEntry *hPtr;
-    Encoding *encodingPtr;
 
     Tcl_MutexLock(&encodingMutex);
     encodingsInitialized  = 0;
     hPtr = Tcl_FirstHashEntry(&encodingTable, &search);
     while (hPtr != NULL) {
-	encodingPtr = (Encoding *) Tcl_GetHashValue(hPtr);
-	if (encodingPtr->freeProc != NULL) {
-	    (*encodingPtr->freeProc)(encodingPtr->clientData);
-	}
-	ckfree((char *) encodingPtr->name);
-	ckfree((char *) encodingPtr);
-	hPtr = Tcl_NextHashEntry(&search);
+	/*
+	 * Call FreeEncoding instead of doing it directly to handle refcounts
+	 * like escape encodings use.  [Bug #524674]
+	 * Make sure to call Tcl_FirstHashEntry repeatedly so that all
+	 * encodings are eventually cleaned up.
+	 */
+	FreeEncoding((Tcl_Encoding) Tcl_GetHashValue(hPtr));
+	hPtr = Tcl_FirstHashEntry(&encodingTable, &search);
     }
     Tcl_DeleteHashTable(&encodingTable);
     Tcl_MutexUnlock(&encodingMutex);
