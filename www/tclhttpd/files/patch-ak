--- src/limit.c	Thu May  1 19:42:14 2003
+++ src/limit.c	Fri Nov 19 13:21:15 2004
@@ -9,6 +9,5 @@
 
 
-static int  LimitCmd _ANSI_ARGS_((ClientData clientData,
-            Tcl_Interp *interp, int argc, char *argv[]));
+Tcl_ObjCmdProc  LimitCmd;
 
 #undef TCL_STORAGE_CLASS
@@ -29,9 +28,8 @@
  */
 int
-LimitCmd(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
+LimitCmd(ClientData data, Tcl_Interp *interp, int argc, Tcl_Obj *CONST objv[])
 {
-    int max;
-    char buf[32];
     struct rlimit limit;
+    Tcl_Obj *limObj[2];
     Tcl_ResetResult(interp);
     if (getrlimit(RLIMIT_NOFILE, &limit) < 0) {
@@ -40,12 +38,18 @@
     }
     if (argc > 1) {
-    Tcl_GetInt(interp, argv[1], (int *)&limit.rlim_cur);
+        long	rlim_cur;
+
+        if (Tcl_GetLongFromObj(interp, objv[1], &rlim_cur) != TCL_OK)
+            return TCL_ERROR;
+        limit.rlim_cur = rlim_cur;
         if (setrlimit(RLIMIT_NOFILE, &limit) < 0) {
-        Tcl_AppendResult(interp, "NOFILE: ", Tcl_PosixError(interp), NULL);
-        return TCL_ERROR;
-    }
+            Tcl_AppendResult(interp, "NOFILE: ", Tcl_PosixError(interp), NULL);
+            return TCL_ERROR;
+        }
     }
     /* bad, bad style, direct writing to interp->result */
-    sprintf(interp->result, "%d %d", limit.rlim_cur, limit.rlim_max);
+    limObj[0] = Tcl_NewLongObj((long)limit.rlim_cur);
+    limObj[1] = Tcl_NewLongObj((long)limit.rlim_max);
+    Tcl_SetObjResult(interp, Tcl_NewListObj(2, limObj));
     return TCL_OK;
 }
@@ -71,5 +75,5 @@
     #endif
 
-    Tcl_CreateCommand(interp, "limit", LimitCmd, NULL, NULL);
+    Tcl_CreateObjCommand(interp, "limit", LimitCmd, NULL, NULL);
     code = Tcl_PkgProvide(interp, "limit", "1.0");
     if (code != TCL_OK) {
