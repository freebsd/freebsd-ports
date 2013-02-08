--- drivers/ntk.c.orig
+++ drivers/ntk.c
@@ -115,7 +115,7 @@
         //
         sprintf( scmd, "send %s {%s}", rem_interp, cmd ); // mess! make it more efficient
         if ( Tcl_Eval( interp, scmd ) != TCL_OK )
-            fprintf( stderr, "%s\n", interp->result );
+            fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
     }
 }
 
@@ -264,7 +264,7 @@
         sprintf( cmd, "send %s \"set client [tk appname]; wm deiconify .\"", rem_interp );
         if ( Tcl_Eval( interp, cmd ) != TCL_OK )
         {
-            fprintf( stderr, "%s\n", interp->result );
+            fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
             plexit( "No such tk server." );
         }
     }
@@ -301,7 +301,7 @@
     // Set up device parameters
 
     Tcl_Eval( interp, "tk scaling" ); // pixels per mm
-    ppm = (PLFLT) atof( interp->result ) / ( 25.4 / 72. );
+    ppm = (PLFLT) atof( Tcl_GetStringResult(interp) ) / ( 25.4 / 72. );
     plP_setpxl( ppm, ppm );
     plP_setphy( xmin, xmax * scale, ymin, ymax * scale );
 }
@@ -371,11 +371,11 @@
         {
             tk_cmd( "update" );
             tk_cmd( "info exists keypress" );
-            sscanf( interp->result, "%d", &st );
+            sscanf( Tcl_GetStringResult(interp), "%d", &st );
         }
 
         tk_cmd( "set keypress" );
-        sscanf( interp->result, "%d", &key );
+        sscanf( Tcl_GetStringResult(interp), "%d", &key );
 //fprintf(stderr,"\n%d\n", key);fflush(stderr);
         tk_cmd( "unset keypress" );
         st = 0;
@@ -433,7 +433,7 @@
         {
             tk_cmd( "update" );
             tk_cmd( "winfo exists $plf.f2.c$ccanv" );
-            sscanf( interp->result, "%d", &st );
+            sscanf( Tcl_GetStringResult(interp), "%d", &st );
         }
         st = 0;
         // this give a "Segmentation fault", even after checking for the canvas!
@@ -450,16 +450,16 @@
     {
         tk_cmd( "update" );
         tk_cmd( "info exists xloc" );
-        sscanf( interp->result, "%d", &st );
+        sscanf( Tcl_GetStringResult(interp), "%d", &st );
     }
     tk_cmd( "set xloc" );
-    sscanf( interp->result, "%d", &gin.pX );
+    sscanf( Tcl_GetStringResult(interp), "%d", &gin.pX );
     tk_cmd( "set yloc" );
-    sscanf( interp->result, "%d", &gin.pY );
+    sscanf( Tcl_GetStringResult(interp), "%d", &gin.pY );
     tk_cmd( "set bloc" );
-    sscanf( interp->result, "%d", &gin.button );
+    sscanf( Tcl_GetStringResult(interp), "%d", &gin.button );
     tk_cmd( "set sloc" );
-    sscanf( interp->result, "%d", &gin.state );
+    sscanf( Tcl_GetStringResult(interp), "%d", &gin.state );
 
     gin.dX = (PLFLT) gin.pX / xmax;
     gin.dY = 1. - (PLFLT) gin.pY / ymax;
