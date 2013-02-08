--- drivers/tk.c.orig
+++ drivers/tk.c
@@ -764,7 +764,7 @@
 
     if ( Tcl_Init( dev->interp ) != TCL_OK )
     {
-        fprintf( stderr, "%s\n", dev->interp->result );
+        fprintf( stderr, "%s\n", Tcl_GetStringResult(dev->interp) );
         abort_session( pls, "Unable to initialize Tcl" );
     }
 
@@ -1568,7 +1568,7 @@
                  0, 1, ( ClientData ) & iodev->file ) != TCL_OK )
         {
             fprintf( stderr, "Cannot get file info:\n\t %s\n",
-                dev->interp->result );
+                Tcl_GetStringResult(dev->interp) );
             abort_session( pls, "" );
         }
         iodev->fd = fileno( iodev->file );
@@ -1673,7 +1673,7 @@
         if ( pl_PacketSend( dev->interp, dev->iodev, pls->pdfs ) )
         {
             fprintf( stderr, "Packet send failed:\n\t %s\n",
-                dev->interp->result );
+                Tcl_GetStringResult(dev->interp) );
             abort_session( pls, "" );
         }
         pdfs->bp = 0;
@@ -2131,7 +2131,7 @@
 
     if ( Tk_Init( interp ) )
     {
-        fprintf( stderr, "tk_init:%s\n", interp->result );
+        fprintf( stderr, "tk_init:%s\n", Tcl_GetStringResult(interp) );
         return 1;
     }
 
@@ -2165,7 +2165,7 @@
         if ( Tcl_ExprBoolean( dev->interp, dev->cmdbuf, &result ) )
         {
             fprintf( stderr, "tk_wait command \"%s\" failed:\n\t %s\n",
-                cmd, dev->interp->result );
+                cmd, Tcl_GetStringResult(dev->interp) );
             break;
         }
         if ( result )
@@ -2225,7 +2225,7 @@
     if ( result != TCL_OK )
     {
         fprintf( stderr, "Server command \"%s\" failed:\n\t %s\n",
-            cmd, dev->interp->result );
+            cmd, Tcl_GetStringResult(dev->interp) );
         abort_session( pls, "" );
     }
 }
@@ -2247,7 +2247,7 @@
     if ( Tcl_VarEval( dev->interp, cmd, (char **) NULL ) != TCL_OK )
     {
         fprintf( stderr, "TCL command \"%s\" failed:\n\t %s\n",
-            cmd, dev->interp->result );
+            cmd, Tcl_GetStringResult(dev->interp) );
         abort_session( pls, "" );
     }
 }
