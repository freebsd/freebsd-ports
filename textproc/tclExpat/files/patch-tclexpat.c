--- tclexpat.c.orig	1998-08-22 09:35:44.000000000 +0200
+++ tclexpat.c	2013-05-13 12:11:18.000000000 +0200
@@ -18,8 +18,9 @@
  *
  */
 
+#include <string.h>
 #include <tcl.h>
-#include "xmlparse.h"
+#include <expat.h>
 
 /*
  * The structure below is used to refer to an expat parser object.
@@ -53,6 +54,8 @@
  * Prototypes for procedures defined later in this file:
  */
 
+int Tclexpat_Init (Tcl_Interp *);
+static void TclExpatHandlerResult(TclExpatInfo *, int result);
 static Tcl_ObjCmdProc TclExpatObjCmd;
 static Tcl_ObjCmdProc TclExpatInstanceCmd;
 static Tcl_CmdDeleteProc TclExpatDeleteCmd;
@@ -72,32 +75,32 @@
 				       int objc,
 				       Tcl_Obj *CONST objv[]));
 
-static void * (TclExpatElementStartHandler) _ANSI_ARGS_((void *userdata,
+static void (TclExpatElementStartHandler) _ANSI_ARGS_((void *userdata,
 							 const XML_Char *name,
 							 const XML_Char **atts));
-static void * (TclExpatElementEndHandler) _ANSI_ARGS_((void *userData,
+static void (TclExpatElementEndHandler) _ANSI_ARGS_((void *userData,
 						       const XML_Char *name));
-static void * (TclExpatCharacterDataHandler) _ANSI_ARGS_((void *userData,
+static void (TclExpatCharacterDataHandler) _ANSI_ARGS_((void *userData,
 							  const XML_Char *s,
 							  int len));
-static void * (TclExpatProcessingInstructionHandler) _ANSI_ARGS_((void *userData,
+static void (TclExpatProcessingInstructionHandler) _ANSI_ARGS_((void *userData,
 								  const XML_Char *target,
 								  const XML_Char *data));
-static void * (TclExpatExternalEntityRefHandler) _ANSI_ARGS_((XML_Parser parser,
+static int (TclExpatExternalEntityRefHandler) _ANSI_ARGS_((XML_Parser parser,
 							      const XML_Char *openEntityNames,
 							      const XML_Char *base,
 							      const XML_Char *systemId,
 							      const XML_Char *publicId));
-static void * (TclExpatDefaultHandler) _ANSI_ARGS_ ((void *userData,
+static void (TclExpatDefaultHandler) _ANSI_ARGS_ ((void *userData,
 						     const XML_Char *s,
 						     int len));
-static void * (TclExpatUnparsedDeclHandler) _ANSI_ARGS_ ((void *userData,
+static void (TclExpatUnparsedDeclHandler) _ANSI_ARGS_ ((void *userData,
 							  const XML_Char *entityname,
 							  const XML_Char *base,
 							  const XML_Char *systemId,
 							  const XML_Char *publicId,
 							  const XML_Char *notationName));
-static void * (TclExpatNotationDeclHandler) _ANSI_ARGS_ ((void *userData,
+static void (TclExpatNotationDeclHandler) _ANSI_ARGS_ ((void *userData,
 							  const XML_Char *notationName,
 							  const XML_Char *base,
 							  const XML_Char *systemId,
@@ -106,7 +109,7 @@
 							 const XML_Char *name,
 							 XML_Encoding *info));
 
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8) && !defined(Tcl_GetString)
 
 /*
  *----------------------------------------------------------------------------
@@ -134,7 +137,7 @@
   s = Tcl_GetStringFromObj(obj, &i);
   return s;
 }
-#endif /* TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0 */
+#endif /* TCL_MAJOR_VERSION >= 8 */
 
 /*
  *----------------------------------------------------------------------------
@@ -157,6 +160,10 @@
      Tcl_Interp *interp; /* Interpreter to initialise. */
 {
 
+  if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
+    return TCL_ERROR;
+  }
+
   Tcl_PkgProvide(interp, "expat", "1.1");
 
   Tcl_CreateObjCommand(interp, "expat", TclExpatObjCmd, NULL, NULL);
@@ -267,7 +274,6 @@
      Tcl_Interp *interp;
      TclExpatInfo *expat;
 {
-  int len;
 
   if (!(expat->parser = XML_ParserCreate(NULL))) {
     Tcl_SetResult(interp, "unable to create expat parser", NULL);
@@ -284,22 +290,22 @@
    */
 
   XML_SetElementHandler(expat->parser,
-			(XML_StartElementHandler) TclExpatElementStartHandler,
-			(XML_EndElementHandler) TclExpatElementEndHandler);
+			TclExpatElementStartHandler,
+			TclExpatElementEndHandler);
   XML_SetCharacterDataHandler(expat->parser,
-			      (XML_CharacterDataHandler) TclExpatCharacterDataHandler);
+			      TclExpatCharacterDataHandler);
   XML_SetProcessingInstructionHandler(expat->parser,
-				      (XML_ProcessingInstructionHandler) TclExpatProcessingInstructionHandler);
+				      TclExpatProcessingInstructionHandler);
   XML_SetDefaultHandler(expat->parser,
-			(XML_DefaultHandler) TclExpatDefaultHandler);
+			TclExpatDefaultHandler);
   XML_SetUnparsedEntityDeclHandler(expat->parser,
-				   (XML_UnparsedEntityDeclHandler) TclExpatUnparsedDeclHandler);
+				   TclExpatUnparsedDeclHandler);
   XML_SetNotationDeclHandler(expat->parser,
-			     (XML_NotationDeclHandler) TclExpatNotationDeclHandler);
+			     TclExpatNotationDeclHandler);
   XML_SetExternalEntityRefHandler(expat->parser,
-				  (XML_ExternalEntityRefHandler) TclExpatExternalEntityRefHandler);
+				  TclExpatExternalEntityRefHandler);
   XML_SetUnknownEncodingHandler(expat->parser,
-				(XML_UnknownEncodingHandler) TclExpatUnknownEncodingHandler,
+				TclExpatUnknownEncodingHandler,
 				(void *) expat);
   XML_SetUserData(expat->parser,
 		  (void *) expat);
@@ -327,7 +333,6 @@
 TclExpatFreeParser(expat)
      TclExpatInfo *expat;
 {
-  int len;
 
   XML_ParserFree(expat->parser);
   expat->parser = NULL;
@@ -357,9 +362,9 @@
      Tcl_Obj *CONST objv[];
 {
   TclExpatInfo *expat = (TclExpatInfo *) clientData;
-  char *method, *data;
+  char *data;
   int len, index, result = TCL_OK;
-  static char *options[] = {
+  static CONST char * options[] = {
     "configure", "cget", "parse", "reset", NULL
   };
   enum options {
@@ -464,10 +469,10 @@
 
   if (!result) {
     Tcl_ResetResult(interp);
-    sprintf(s, "%d", XML_GetCurrentLineNumber(expat->parser));
+    sprintf(s, "%ld", (long)XML_GetCurrentLineNumber(expat->parser));
     Tcl_AppendResult(interp, "error \"", XML_ErrorString(XML_GetErrorCode(expat->parser)),
 		     "\" at line ", s, " character ", NULL);
-    sprintf(s, "%d", XML_GetCurrentColumnNumber(expat->parser));
+    sprintf(s, "%ld", (long)XML_GetCurrentColumnNumber(expat->parser));
     Tcl_AppendResult(interp, s, NULL);
 
     return TCL_ERROR;
@@ -514,7 +519,7 @@
      int objc;
      Tcl_Obj *CONST objv[];
 {
-  static char *switches[] = {
+  static CONST char *switches[] = {
     "-final",
     "-baseurl", 
     "-elementstartcommand",
@@ -688,7 +693,7 @@
   }
 
   if (doParse) {
-    return TclExpatParse(interp, expat->parser, "", 0);
+    return TclExpatParse(interp, expat, "", 0);
   } else {
     return TCL_OK;
   }
@@ -739,7 +744,7 @@
  *----------------------------------------------------------------------------
  */
 
-void
+static void
 TclExpatHandlerResult(expat, result)
      TclExpatInfo *expat;
      int result;
@@ -795,7 +800,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatElementStartHandler(userData, name, atts)
      void *userData;
      const char *name;
@@ -828,8 +833,8 @@
 
   atList = Tcl_NewListObj(0, NULL);
   for (atPtr = atts; atPtr[0] && atPtr[1]; atPtr += 2) {
-    Tcl_ListObjAppendElement(expat->interp, atList, Tcl_NewStringObj((char *)atPtr[0], strlen(atPtr[0])));
-    Tcl_ListObjAppendElement(expat->interp, atList, Tcl_NewStringObj((char *)atPtr[1], strlen(atPtr[1])));
+    Tcl_ListObjAppendElement(expat->interp, atList, Tcl_NewStringObj(atPtr[0], -1));
+    Tcl_ListObjAppendElement(expat->interp, atList, Tcl_NewStringObj(atPtr[1], -1));
   }
 
   /*
@@ -840,14 +845,14 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)name, strlen(name)));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(name, -1));
   Tcl_ListObjAppendElement(expat->interp, cmdPtr, atList);
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -877,7 +882,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatElementEndHandler(userData, name)
      void *userData;
      CONST char *name;
@@ -911,13 +916,13 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)name, strlen(name)));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(name, -1));
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -947,7 +952,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatCharacterDataHandler(userData, s, len)
      void *userData;
      CONST char *s;
@@ -970,13 +975,13 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)s, len));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(s, len));
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1006,7 +1011,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatProcessingInstructionHandler(userData, target, data)
      void *userData;
      CONST char *target;
@@ -1029,14 +1034,14 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)target, strlen(target)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)data, strlen(data)));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(target, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(data, -1));
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1066,7 +1071,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatDefaultHandler(userData, s, len)
      void *userData;
      CONST char *s;
@@ -1089,13 +1094,13 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)s, len));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(s, len));
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1125,7 +1130,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatUnparsedDeclHandler(userData, entityname, base, systemId, publicId, notationName)
      void *userData;
      CONST char *entityname;
@@ -1151,25 +1156,25 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)entityname, strlen(entityname)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)base, strlen(base)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)systemId, strlen(systemId)));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(entityname, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(base, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(systemId, -1));
   if (publicId == NULL) {
     Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewListObj(0, NULL));
   } else {
-    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)publicId, strlen(publicId)));
+    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(publicId, -1));
   }
   if (notationName == NULL) {
     Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewListObj(0, NULL));
   } else {
-    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)notationName, strlen(notationName)));
+    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(notationName, -1));
   }
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1199,7 +1204,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static void
 TclExpatNotationDeclHandler(userData, notationName, base, systemId, publicId)
      void *userData;
      CONST char *notationName;
@@ -1224,24 +1229,24 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)notationName, strlen(notationName)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)base, strlen(base)));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(notationName, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(base, -1));
   if (systemId == NULL) {
     Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewListObj(0, NULL));
   } else {
-    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)systemId, strlen(systemId)));
+    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(systemId, -1));
   }
   if (publicId == NULL) {
     Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewListObj(0, NULL));
   } else {
-    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)publicId, strlen(publicId)));
+    Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(publicId, -1));
   }
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1279,15 +1284,18 @@
      XML_Encoding *info;
 {
   TclExpatInfo *expat = (TclExpatInfo *) encodingHandlerData;
+#if 0
   Tcl_Obj *cmdPtr;
   int result;
+#endif
 
   Tcl_SetResult(expat->interp, "not implemented", NULL);
-  return 0;
+  return 1;
 
+#if 0
   if (expat->unknownencodingcommand == NULL ||
       expat->status != TCL_OK) {
-    return;
+    return 1;
   }
 
   /*
@@ -1306,7 +1314,7 @@
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1317,7 +1325,8 @@
 
   TclExpatHandlerResult(expat, result);
 
-  return;
+  return 0;
+#endif
 }
 
 /*
@@ -1336,7 +1345,7 @@
  *----------------------------------------------------------------------------
  */
 
-static void *
+static int
 TclExpatExternalEntityRefHandler(parser, openEntityNames, base, systemId, publicId)
      XML_Parser parser;
      CONST char *openEntityNames;
@@ -1350,7 +1359,7 @@
 
   if (expat->externalentitycommand == NULL ||
       expat->status != TCL_OK) {
-    return;
+    return 0;
   }
 
   /*
@@ -1361,16 +1370,16 @@
   Tcl_IncrRefCount(cmdPtr);
   Tcl_Preserve((ClientData) expat->interp);
 
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)openEntityNames, strlen(openEntityNames)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)base, strlen(base)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)systemId, strlen(systemId)));
-  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj((char *)publicId, strlen(publicId)));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(openEntityNames, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(base, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(systemId, -1));
+  Tcl_ListObjAppendElement(expat->interp, cmdPtr, Tcl_NewStringObj(publicId, -1));
 
   /*
    * It would be desirable to be able to terminate parsing
    * if the return result is TCL_ERROR or TCL_BREAK.
    */
-#if (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 0)
+#if (TCL_MAJOR_VERSION >= 8)
   result = Tcl_GlobalEvalObj(expat->interp, cmdPtr);
 #else
   result = Tcl_EvalObj(expat->interp, cmdPtr, TCL_EVAL_GLOBAL);
@@ -1381,7 +1390,7 @@
 
   TclExpatHandlerResult(expat, result);
 
-  return;
+  return 1;
 }
 
 /*
