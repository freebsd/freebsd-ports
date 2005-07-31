--- cmd/crlutil/crlgen.c	Mon Apr 11 22:24:14 2005
+++ cmd/crlutil/crlgen.c	Fri Jul 29 01:50:48 2005
@@ -53,46 +53,4 @@
 #include "crlgen.h"
 
-
-/* these reroutines were taken from secitem.c, which is supposed to
- * replace this file some day */
-/*
- * This is the hash function.  We simply XOR the encoded form with
- * itself in sizeof(PLHashNumber)-byte chunks.  Improving this
- * routine is left as an excercise for the more mathematically
- * inclined student.
- */
-PLHashNumber PR_CALLBACK
-SECITEM_Hash ( const void *key)
-{
-    const SECItem *item = (const SECItem *)key;
-    PLHashNumber rv = 0;
-
-    PRUint8 *data = (PRUint8 *)item->data;
-    PRUint32 i;
-    PRUint8 *rvc = (PRUint8 *)&rv;
-
-    for( i = 0; i < item->len; i++ ) {
-        rvc[ i % sizeof(rv) ] ^= *data;
-        data++;
-    }
-
-    return rv;
-}
-
-/*
- * This is the key-compare function.  It simply does a lexical
- * comparison on the item data.  This does not result in
- * quite the same ordering as the "sequence of numbers" order,
- * but heck it's only used internally by the hash table anyway.
- */
-PRIntn PR_CALLBACK
-SECITEM_HashCompare ( const void *k1, const void *k2)
-{
-    const SECItem *i1 = (const SECItem *)k1;
-    const SECItem *i2 = (const SECItem *)k2;
-
-    return SECITEM_ItemsAreEqual(i1,i2);
-}
-
 /* Destroys extHandle and data. data was create on heap.
  * extHandle creaded by CERT_StartCRLEntryExtensions. entry
@@ -513,5 +471,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum,
-                          "insufficient number of arguments.\n");
+                          "AddIssuerAltNames: insufficient number of arguments.\n");
         return SECFailure;
     }
@@ -575,5 +533,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum,
-                          "insufficient number of arguments.\n");
+                          "AddCrlNumber: insufficient number of arguments.\n");
         goto loser;
     }
@@ -725,5 +683,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum, 
-                          "insufficient number of arguments.\n");
+                          "%s: insufficient number of arguments.\n", extName);
     }
 
@@ -923,5 +881,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum,
-                          "insufficient number of arguments.\n");
+                          "SetNewRangeField: insufficient number of arguments.\n");
         return SECFailure;
     }
@@ -988,5 +946,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum,
-                          "insufficient number of arguments.\n");
+                          "SetTimeField: insufficient number of arguments.\n");
         return SECFailure;
     }
@@ -1024,5 +982,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum, 
-                          "insufficient number of arguments.\n");
+                          "AddExtension: insufficient number of arguments.\n");
         return SECFailure;
     }
@@ -1042,5 +1000,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum,
-                          "insufficient number of arguments.\n");
+                          "AddExtension(%s) insufficient number of arguments.\n", *extData);
         return SECFailure;
     }
@@ -1078,5 +1036,5 @@
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum,
-                          "insufficient number of arguments.\n");
+                          "AddCert(%s, %s) insufficient number of arguments.\n", certId, revocationDate);
         return SECFailure;
     }
@@ -1362,12 +1362,12 @@
     }
 
     if (extStr->extData == NULL) {
-        extStr->extData = PORT_ZAlloc(MAX_EXT_DATA_LENGTH);
+        extStr->extData = PORT_ZNewArray(char *, MAX_EXT_DATA_LENGTH);
         if (!extStr->extData) {
             return SECFailure;
         }
     }
-    if (extStr->nextUpdatedData > MAX_EXT_DATA_LENGTH) {
+    if (extStr->nextUpdatedData >= MAX_EXT_DATA_LENGTH) {
         PORT_SetError(SEC_ERROR_INVALID_ARGS);
         crlgen_PrintError(crlGenData->parsedLineNum, 
                           "number of fields in extension "
@@ -1415,7 +1415,7 @@
               PORT_Free(crlGenData->certEntry);
               break;
           case CRLGEN_ADD_EXTENSION_CONTEXT:
-              if (crlGenData->extensionEntry->nextUpdatedData) {
+              if (crlGenData->extensionEntry->extData) {
                   int i = 0;
                   for (;i < crlGenData->extensionEntry->nextUpdatedData;i++)
                       PORT_Free(*(crlGenData->extensionEntry->extData + i));
