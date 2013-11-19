--- generic/bltBgexec.c.orig	2013-11-18 16:52:13.000000000 +0100
+++ generic/bltBgexec.c	2013-11-18 16:53:58.000000000 +0100
@@ -926,7 +926,7 @@
         Tcl_DStringInit(&dStr);
         GetSinkData(sinkPtr, &data, &length);
         Tcl_DStringAppend(&dStr, sinkPtr->command, -1);
-        Tcl_DStringAppendElement(&dStr, data);
+        Tcl_DStringAppendElement(&dStr, (const char *)data);
         Tcl_DStringAppendElement(&dStr, status);
         if (Tcl_GlobalEval(interp, Tcl_DStringValue(&dStr)) != TCL_OK) {
             Tcl_BackgroundError(interp);
