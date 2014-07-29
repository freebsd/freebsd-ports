--- src/stubs.c.orig	2007-01-04 18:47:55.000000000 +0100
+++ src/stubs.c	2013-05-22 17:34:59.000000000 +0200
@@ -11,10 +11,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <tcl.h>
-#include <tk.h>
 #include <wn.h>
 
-static char *Id = "$Id: stubs.c,v 1.7 2005/04/29 19:01:57 wn Exp $";
+__FBSDID("$Id: stubs.c,v 1.7 2005/04/29 19:01:57 wn Exp $");
 
 static char resultbuf[SEARCHBUF];
 
@@ -33,26 +32,26 @@
 ** the search word's base form.
 */
 
-int wn_findvalidsearches (ClientData clientData, Tcl_Interp *interp, 
-   int argc, char *argv[]) {
+static int
+wn_findvalidsearches (ClientData clientData, Tcl_Interp *interp, 
+   int argc, Tcl_Obj * const objv[]) {
    unsigned int bitfield;
-   static char bitfieldstr[32];
-   char *morph;
+   const char *morph;
    int pos;
    if (argc != 3) {
-      interp -> result = 
-         "usage: findvalidsearches searchword partofspeechnum";
+      Tcl_WrongNumArgs(interp, 1, objv,
+         "findvalidsearches searchword partofspeechnum");
       return TCL_ERROR;
    }
-   pos = atoi (argv[2]);
-   bitfield = is_defined (argv[1], pos);
-   if ((morph = morphstr (argv[1], pos)) != NULL) {
+   if (Tcl_GetIntFromObj(interp, objv[2], &pos) != TCL_OK)
+      return TCL_ERROR;
+   bitfield = is_defined (Tcl_GetString(objv[1]), pos);
+   if ((morph = morphstr (Tcl_GetString(objv[1]), pos)) != NULL) {
       do {
          bitfield |= is_defined (morph, pos);
       } while ((morph = morphstr (NULL, pos)) != NULL);
    }
-   sprintf (bitfieldstr, "%u", bitfield);
-   interp -> result = bitfieldstr;
+   Tcl_SetObjResult(interp, Tcl_NewIntObj(bitfield));
    return TCL_OK;
 }
 
@@ -63,19 +62,17 @@
 ** the results of findvalidsearches.  Invoked from Tcl as "bit".
 */
 
-int wn_bit (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
-   unsigned int bitfield;
-   static char bitfieldstr[32];
+static int
+wn_bit (ClientData clientData, Tcl_Interp *interp,
+   int argc, Tcl_Obj * const objv[]) {
    int whichbit;
    if (argc != 2) {
-      interp -> result = "usage: bit bitnum";
+      Tcl_WrongNumArgs(interp, 1, objv, "bitnum");
       return TCL_ERROR;
    }
-   whichbit = atoi (argv[1]);
-   bitfield = bit (whichbit);
-   sprintf (bitfieldstr, "%u", bitfield);
-   interp -> result = bitfieldstr;
+   if (Tcl_GetIntFromObj(interp, objv[1], &whichbit) != TCL_OK)
+	return TCL_ERROR;
+   Tcl_SetObjResult(interp, Tcl_NewIntObj(bit(whichbit)));
    return TCL_OK;
 } 
 
@@ -84,13 +81,13 @@
 ** It is invoked from Tcl simply as "search".
 */
 
-int wn_search (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_search (ClientData clientData, Tcl_Interp *interp,
+   int argc, const char * argv[]) {
    int pos, searchtype, sense;
-   char *morph;
+   const char *morph;
    if (argc != 5) {
-      interp -> result = 
-         "usage: search searchword partofspeechnum searchtypenum sensenum";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj ("usage: search searchword partofspeechnum searchtypenum sensenum", -1));
       return TCL_ERROR;
    }
    pos = atoi (argv[2]);
@@ -102,7 +99,7 @@
          strcat (resultbuf, findtheinfo (morph, pos, searchtype, sense));
       } while ((morph = morphstr (NULL, pos)) != NULL);
    }
-   interp -> result = resultbuf;
+   Tcl_SetObjResult(interp, Tcl_NewStringObj(resultbuf, -1));
    return TCL_OK;
 }
 
@@ -111,10 +108,11 @@
 ** results.
 */
  
-int wn_glosses (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_glosses (ClientData clientData, Tcl_Interp *interp,
+   int argc, const char *argv[]) {
    if (argc != 2) {
-      interp -> result = "usage: glosses [1 | 0]";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj("usage: glosses [1 | 0]", -1));
       return TCL_ERROR;
    }
    dflag = atoi (argv[1]);
@@ -126,10 +124,11 @@
 ** results.
 */
  
-int wn_fileinfo (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_fileinfo (ClientData clientData, Tcl_Interp *interp,
+   int argc, const char *argv[]) {
    if (argc != 2) {
-      interp -> result = "usage: fileinfo [1 | 0]";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj("usage: fileinfo [1 | 0]", -1));
       return TCL_ERROR;
    }
    fileinfoflag = atoi (argv[1]);
@@ -141,10 +140,11 @@
 ** in the search results.
 */
  
-int wn_byteoffset (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_byteoffset (ClientData clientData, Tcl_Interp *interp,
+   int argc, const char *argv[]) {
    if (argc != 2) {
-      interp -> result = "usage: byteoffset [1 | 0]";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj("usage: byteoffset [1 | 0]", -1));
       return TCL_ERROR;
    }
    offsetflag = atoi (argv[1]);
@@ -156,13 +156,17 @@
 ** returned.
 */
  
-int wn_senseflag (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_senseflag (ClientData clientData, Tcl_Interp *interp,
+   int argc, Tcl_Obj * const objv[]) {
    if (argc != 2) {
-      interp -> result = "usage: senseflag [1 | 0]";
+      Tcl_WrongNumArgs(interp, 0, objv, "?1|0?"); 
       return TCL_ERROR;
    }
-   wnsnsflag = atoi (argv[1]);
+   if (Tcl_GetBooleanFromObj(interp, objv[1], &argc) != TCL_OK)
+      return TCL_ERROR;
+
+   wnsnsflag = argc; /* argc got recycled here */
    return TCL_OK;
 }
 
@@ -171,26 +175,30 @@
 ** type of search does.
 */
 
-int wn_contextualhelp (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_contextualhelp (ClientData clientData, Tcl_Interp *interp,
+   int argc, Tcl_Obj * const objv[]) {
    int pos, searchtype;
    if (argc != 3) {
-      interp -> result = "usage: contextualhelp partofspeechnum searchtypenum";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj("usage: contextualhelp partofspeechnum searchtypenum", -1));
       return TCL_ERROR;
    }
-   pos = atoi (argv[1]);
-   searchtype = atoi (argv[2]);
-   interp -> result = helptext[pos][searchtype];
+   if (Tcl_GetIntFromObj(interp, objv[1], &pos) != TCL_OK ||
+       Tcl_GetIntFromObj(interp, objv[2], &searchtype) != TCL_OK)
+	return TCL_ERROR;
+   /* Dropping const-ness below is Ok, because TCL_STATIC tells Tcl to DTRT */
+   Tcl_SetResult(interp, (char *)helptext[pos][searchtype], TCL_STATIC);
    return TCL_OK;
 }
 
 /* This command, accessed in Tcl as "reopendb" reopens the WordNet database.
 */
 
-int wn_reopendb (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_reopendb (ClientData clientData, Tcl_Interp *interp,
+   int argc, Tcl_Obj * const objv[]) {
    if (argc != 1) {
-      interp -> result = "usage: reopendb";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj("usage: reopendb", -1));
       return TCL_ERROR;
    }
    re_wninit ();
@@ -201,22 +209,40 @@
 ** stop whatever search it is currently in the middle of performing.
 */
 
-int wn_abortsearch (ClientData clientData, Tcl_Interp *interp,
-   int argc, char *argv[]) {
+static int
+wn_abortsearch (ClientData clientData, Tcl_Interp *interp,
+   int argc, Tcl_Obj * const objv[]) {
    if (argc != 1) {
-      interp -> result = "usage: abortsearch";
+      Tcl_SetObjResult(interp, Tcl_NewStringObj("usage: abortsearch", -1));
       return TCL_ERROR;
    }
    abortsearch = 1;
    return TCL_OK;
 }
 
+/* Return text of the license. The license is compiled in anyway, so
+** there is not point in keeping another copy in a separate file.
+*/
+static int
+wn_license(ClientData clientData, Tcl_Interp *interp,
+   int objc, Tcl_Obj * const objv[]) {
+   if (objc != 1) {
+      Tcl_WrongNumArgs(interp, 0, objv, "no arguments");
+      return TCL_ERROR;
+   }
+   /* Dropping the const is Ok, as we supply TCL_STATIC to TCL API */
+   Tcl_SetResult(interp, (char *)license, TCL_STATIC);
+   return TCL_OK;
+}
+    
+
 /* This is a callback function invoked by the WordNet search engine every so
 ** often, to allow the interface to respond to events (especially the pressing
 ** of a stop button) during the search.
 */
 
-void tkwn_doevents (void) {
+static void
+tkwn_doevents (void) {
    while (Tcl_DoOneEvent (TCL_WINDOW_EVENTS | TCL_DONT_WAIT) != 0) {}
 }
 
@@ -225,13 +251,14 @@
 ** specific, since it uses the native error reporting mechanism.
 */
 
-int tkwn_displayerror (char *msg) {
+static int
+tkwn_displayerror (const char *msg) {
 #ifdef _WINDOWS
    MessageBeep (MB_ICONEXCLAMATION);
    MessageBox (NULL, msg, "WordNet Library Error",
       MB_ICONEXCLAMATION | MB_OK | MB_TASKMODAL | MB_SETFOREGROUND);
 #else
-   fprintf (stderr, "%s", msg);
+   fputs(msg, stderr);
 #endif
    return -1;
 }
@@ -245,26 +272,27 @@
    interface_doevents_func = tkwn_doevents;
    display_message = tkwn_displayerror;
    wninit ();
-   Tcl_CreateCommand (interp, "findvalidsearches", (void *) 
+   Tcl_CreateObjCommand (interp, "findvalidsearches",
       wn_findvalidsearches, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "bit", (void *) wn_bit, (ClientData) NULL, 
+   Tcl_CreateObjCommand (interp, "bit", wn_bit, (ClientData) NULL, 
       (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "search", (void *) wn_search, (ClientData) 
+   Tcl_CreateCommand (interp, "search", wn_search, (ClientData) 
       NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "glosses", (void *) wn_glosses, (ClientData) 
+   Tcl_CreateCommand (interp, "glosses", wn_glosses, (ClientData) 
       NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "fileinfo", (void *) wn_fileinfo, (ClientData) 
+   Tcl_CreateCommand (interp, "fileinfo", wn_fileinfo, (ClientData) 
       NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "byteoffset", (void *) wn_byteoffset, 
+   Tcl_CreateCommand (interp, "byteoffset", wn_byteoffset, 
       (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "senseflag", (void *) wn_senseflag, 
+   Tcl_CreateObjCommand (interp, "senseflag", wn_senseflag, 
       (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "contextualhelp", (void *) wn_contextualhelp,
+   Tcl_CreateObjCommand (interp, "contextualhelp", wn_contextualhelp,
       (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "reopendb", (void *) wn_reopendb, (ClientData)
+   Tcl_CreateObjCommand (interp, "reopendb", wn_reopendb, (ClientData)
       NULL, (Tcl_CmdDeleteProc *) NULL);
-   Tcl_CreateCommand (interp, "abortsearch", (void *) wn_abortsearch, 
+   Tcl_CreateObjCommand (interp, "abortsearch", wn_abortsearch, 
       (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-   return TCL_OK;
+   Tcl_CreateObjCommand (interp, "wnlicense", wn_license, 
+      (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+   return Tcl_PkgProvide(interp, "Wordnet", "3.0");
 }
-
