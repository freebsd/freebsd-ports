--- bindings/tk-x-plat/plplotter.c.orig
+++ bindings/tk-x-plat/plplotter.c
@@ -463,7 +463,7 @@
     PlPlotterFirstInit( (ClientData) plPlotterPtr );
     Tk_GeometryRequest( plPlotterPtr->tkwin, 200, 200 );
 
-    interp->result = Tk_PathName( plPlotterPtr->tkwin );
+    Tcl_SetResult(interp,(char*)Tk_PathName(plPlotterPtr->tkwin) ,TCL_VOLATILE);
 
     return TCL_OK;
 }
@@ -2018,7 +2018,7 @@
 //
 // Results:
 //      The return value is a standard Tcl result.  If TCL_ERROR is
-//      returned, then interp->result contains an error message.
+//      returned, then Tcl_GetStringResult(interp) contains an error message.
 //
 // Side effects:
 //      Configuration information, such as text string, colors, font, etc.
@@ -2469,7 +2469,7 @@
         plr->at_bop = 0;
         if ( Tcl_Eval( interp, plPlotterPtr->bopCmd ) != TCL_OK )
             fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-                plPlotterPtr->bopCmd, interp->result );
+                plPlotterPtr->bopCmd, Tcl_GetStringResult(interp) );
     }
 
 // Signal eop if necessary
@@ -2479,7 +2479,7 @@
         plr->at_eop = 0;
         if ( Tcl_Eval( interp, plPlotterPtr->eopCmd ) != TCL_OK )
             fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-                plPlotterPtr->eopCmd, interp->result );
+                plPlotterPtr->eopCmd, Tcl_GetStringResult(interp) );
     }
 
     return result;
@@ -2491,7 +2491,7 @@
     {
         if ( Tcl_Eval( interp, plPlotterPtr->eopCmd ) != TCL_OK )
             fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-                plPlotterPtr->eopCmd, interp->result );
+                plPlotterPtr->eopCmd, Tcl_GetStringResult(interp) );
     }
 }
 
@@ -2501,7 +2501,7 @@
     {
         if ( Tcl_Eval( interp, plPlotterPtr->bopCmd ) != TCL_OK )
             fprintf( stderr, "Command \"%s\" failed:\n\t %s\n",
-                plPlotterPtr->bopCmd, interp->result );
+                plPlotterPtr->bopCmd, Tcl_GetStringResult(interp ) );
     }
 }
 
@@ -2536,7 +2536,7 @@
         {
         #endif
             Tcl_AppendResult( interp, "Packet receive failed:\n\t %s\n",
-                interp->result, (char *) NULL );
+                Tcl_GetStringResult(interp), (char *) NULL );
             return TCL_ERROR;
         }
 
@@ -3082,7 +3082,7 @@
 
     if ( argc == 0 )
     {
-        interp->result = "report what?";
+        Tcl_SetResult(interp,(char*)"report what?",TCL_VOLATILE);
         return TCL_ERROR;
     }
 
@@ -3093,7 +3093,7 @@
 
         if ( argc != 3 )
         {
-            interp->result = "Wrong # of args: report wc x y";
+            Tcl_SetResult(interp,(char*)"Wrong # of args: report wc x y",TCL_VOLATILE);
             return TCL_ERROR;
         }
 
@@ -3107,15 +3107,15 @@
 
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
 
