--- ../generic/interpool.c	2009-07-15 08:15:16.000000000 -0400
+++ ../generic/interpool.c	2013-05-12 15:00:06.000000000 -0400
@@ -108,5 +108,4 @@
 {
 
-    int result = 0;
     LogPlugIn *logtoap = NULL;
     Tcl_Obj *code = NULL;
@@ -135,5 +134,5 @@
 
     /* now register here all websh modules */
-    result = Tcl_Init(webInterp->interp);
+    Tcl_Init(webInterp->interp);
     /* checkme: test result */
 
@@ -143,5 +142,5 @@
     Tcl_SetAssocData(webInterp->interp, WEB_APFUNCS_ASSOC_DATA, NULL, (ClientData *) apFuncs);
 
-    result = Websh_Init(webInterp->interp);
+    Websh_Init(webInterp->interp);
 
     /* also register the destrcutor, etc. functions, passing webInterp as
@@ -574,5 +573,5 @@
 #else /* APACHE2 */
 	    ap_log_error(APLOG_MARK, APLOG_NOERRNO | APLOG_ERR, 0,
-			 conf->server, Tcl_GetStringResult(conf->mainInterp));
+			 conf->server, "%s", Tcl_GetStringResult(conf->mainInterp));
 #endif /* APACHE2 */
 	    return 0;
