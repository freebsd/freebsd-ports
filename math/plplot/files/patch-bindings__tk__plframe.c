--- bindings/tk/plframe.c.orig
+++ bindings/tk/plframe.c
@@ -484,7 +484,7 @@
         Tk_DestroyWindow( plFramePtr->tkwin );
         return TCL_ERROR;
     }
-    interp->result = Tk_PathName( plFramePtr->tkwin );
+    Tcl_SetResult(interp,(char*)Tk_PathName( plFramePtr->tkwin) ,TCL_VOLATILE);
 
     return TCL_OK;
 }
@@ -616,7 +616,7 @@
             {
                 bcb.cmd = PLESC_DOUBLEBUFFERING_QUERY;
                 pl_cmd( PLESC_DOUBLEBUFFERING, &bcb );
-                sprintf( interp->result, "%d", bcb.result );
+                sprintf( Tcl_GetStringResult(interp), "%d", bcb.result );
             }
         }
 
@@ -2215,7 +2215,7 @@
 //
 // Results:
 //	The return value is a standard Tcl result.  If TCL_ERROR is
-//	returned, then interp->result contains an error message.
+//	returned, then Tcl_GetStringResult(interp) contains an error message.
 //
 // Side effects:
 //	Configuration information, such as text string, colors, font, etc.
@@ -2675,7 +2675,7 @@
         plr->at_bop = 0;
         if ( Tcl_Eval( interp, plFramePtr->bopCmd ) != TCL_OK )
             fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-                plFramePtr->bopCmd, interp->result );
+                plFramePtr->bopCmd, Tcl_GetStringResult(interp) );
     }
 
 // Signal eop if necessary
@@ -2685,7 +2685,7 @@
         plr->at_eop = 0;
         if ( Tcl_Eval( interp, plFramePtr->eopCmd ) != TCL_OK )
             fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-                plFramePtr->eopCmd, interp->result );
+                plFramePtr->eopCmd, Tcl_GetStringResult(interp) );
     }
 
     return result;
@@ -3275,7 +3275,7 @@
 
     if ( argc == 0 )
     {
-        interp->result = "report what?";
+        Tcl_SetResult(interp,(char*)"report what?",TCL_VOLATILE);
         return TCL_ERROR;
     }
 
@@ -3286,7 +3286,7 @@
 
         if ( argc != 3 )
         {
-            interp->result = "Wrong # of args: report wc x y";
+            Tcl_SetResult(interp,(char*)"Wrong # of args: report wc x y",TCL_VOLATILE);
             return TCL_ERROR;
         }
 
@@ -3300,15 +3300,15 @@
 
         if ( plTranslateCursor( gin ) )
         {
-            sprintf( interp->result, "%f %f", gin->wX, gin->wY );
+            sprintf( Tcl_GetStringResult(interp), "%f %f", gin->wX, gin->wY );
             return TCL_OK;
         }
 
-        interp->result = "Cannot locate";
+        Tcl_SetResult(interp,(char*)"Cannot locate",TCL_VOLATILE);
         return TCL_OK;
     }
 
-    interp->result = "nonsensical request.";
+    Tcl_SetResult(interp,(char*)"nonsensical request.",TCL_VOLATILE);
     return TCL_ERROR;
 }
 
@@ -3324,7 +3324,7 @@
 
     if ( Tcl_Eval( plFramePtr->interp, plFramePtr->bopCmd ) != TCL_OK )
         fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-            plFramePtr->bopCmd, plFramePtr->interp->result );
+            plFramePtr->bopCmd, Tcl_GetStringResult(plFramePtr->interp) );
 }
 
 //--------------------------------------------------------------------------
@@ -3339,7 +3339,7 @@
 
     if ( Tcl_Eval( plFramePtr->interp, plFramePtr->eopCmd ) != TCL_OK )
         fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-            plFramePtr->eopCmd, plFramePtr->interp->result );
+            plFramePtr->eopCmd, Tcl_GetStringResult(plFramePtr->interp) );
 }
 
 //--------------------------------------------------------------------------
