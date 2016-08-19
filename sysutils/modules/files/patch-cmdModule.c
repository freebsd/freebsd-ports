--- cmdModule.c.orig	2016-08-09 09:37:36 UTC
+++ cmdModule.c
@@ -640,8 +640,16 @@ int	 Execute_TclFile(	Tcl_Interp	*interp
             case TCL_OK:	gotPartial = 0;
 			        continue;	/** while **/
 	    
-            case TCL_ERROR:	interp->errorLine = ((linenum-1)-gotPartial) +
-				    interp->errorLine;
+            case TCL_ERROR:	
+#if (TCL_MAJOR_VERSION > 8) \
+	|| (TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION >= 6)
+					Tcl_SetErrorLine(
+							interp,
+							((linenum-1)-gotPartial) + Tcl_GetErrorLine(interp));
+#else
+					interp->errorLine = 
+						((linenum-1)-gotPartial) + interp->errorLine;
+#endif
 	    			/* FALLTHROUGH */
 
             case TCL_LEVEL0_RETURN:
