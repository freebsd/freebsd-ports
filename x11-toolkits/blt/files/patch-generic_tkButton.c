--- generic/tkButton.c.orig	2013-10-30 12:11:35.000000000 +0100
+++ generic/tkButton.c	2013-10-30 12:15:13.000000000 +0100
@@ -864,8 +864,6 @@
 static Blt_TileChangedProc TileChangedProc;
 static Tcl_CmdProc ButtonCmd, LabelCmd, CheckbuttonCmd, RadiobuttonCmd;
 
-EXTERN int TkCopyAndGlobalEval _ANSI_ARGS_((Tcl_Interp *interp, char *script));
-
 #if (TK_MAJOR_VERSION > 4)
 EXTERN void TkComputeAnchor _ANSI_ARGS_((Tk_Anchor anchor, Tk_Window tkwin, 
 	int padX, int padY, int innerWidth, int innerHeight, int *xPtr, 
@@ -3292,7 +3290,12 @@
 	}
     }
     if ((butPtr->type > TYPE_LABEL) && (butPtr->command != NULL)) {
-	return TkCopyAndGlobalEval(butPtr->interp, butPtr->command);
+        Tcl_DString buf;
+        Tcl_DStringInit(&buf);
+        Tcl_DStringAppend(&buf, butPtr->command, -1);
+        int code = Tcl_EvalEx(butPtr->interp, Tcl_DStringValue(&buf), Tcl_DStringLength(&buf), TCL_EVAL_GLOBAL);
+        Tcl_DStringFree(&buf);
+	return code;
     }
     return TCL_OK;
 }
