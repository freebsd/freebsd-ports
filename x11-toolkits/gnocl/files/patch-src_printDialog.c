--- src/printDialog.c.orig	2013-09-17 10:02:23.000000000 +0200
+++ src/printDialog.c	2013-09-17 10:14:13.000000000 +0200
@@ -17,6 +17,7 @@
 **/
 
 #include "gnocl.h"
+#include <gtk-unix-print-2.0/gtk/gtkprintunixdialog.h>
 
 /* static declarations */
 static int gnoclOptPageSetup ( Tcl_Interp *interp, GnoclOption *opt, GObject *obj, Tcl_Obj **ret );
@@ -64,67 +65,28 @@
 
 	GtkPrintCapabilities capability;
 
-	switch  ( *opt->propName )
-	{
-
-		case 'page-set':
-			{
-				capability = GTK_PRINT_CAPABILITY_PAGE_SET;
-			}
-			break;
-		case 'copies':
-			{
-				capability = GTK_PRINT_CAPABILITY_COPIES;
-			}
-			break;
-		case 'collate':
-			{
-				capability =  GTK_PRINT_CAPABILITY_COLLATE ;
-			}
-			break;
-		case 'reverse':
-			{
-				capability =  GTK_PRINT_CAPABILITY_REVERSE ;
-			}
-			break;
-		case 'scale':
-			{
-				capability =  GTK_PRINT_CAPABILITY_SCALE ;
-			}
-			break;
-		case 'generate-pdf':
-			{
-				capability =  GTK_PRINT_CAPABILITY_GENERATE_PDF ;
-			}
-			break;
-		case 'generate-ps':
-			{
-				capability =  GTK_PRINT_CAPABILITY_GENERATE_PS ;
-			}
-			break;
-		case 'preview':
-			{
-				capability = GTK_PRINT_CAPABILITY_PREVIEW ;
-			}
-			break;
-		case 'number-up':
-			{
-				capability =  GTK_PRINT_CAPABILITY_NUMBER_UP ;
-			}
-			break;
-		case ' number-up-layout':
-			{
-				capability =  GTK_PRINT_CAPABILITY_NUMBER_UP_LAYOUT ;
-			}
-			break;
-		default:
-			{
-				// assert( 0 );
-				return TCL_ERROR;
-			}
-
-	}
-
+    if ( ! strcmp ( opt->propName, "page-set" ) )
+        capability = GTK_PRINT_CAPABILITY_PAGE_SET;
+    else if ( ! strcmp ( opt->propName, "copies" ) )
+        capability = GTK_PRINT_CAPABILITY_COPIES;
+    else if ( ! strcmp ( opt->propName, "collate" ) )
+        capability =  GTK_PRINT_CAPABILITY_COLLATE;
+    else if ( ! strcmp ( opt->propName, "reverse" ) )
+        capability =  GTK_PRINT_CAPABILITY_REVERSE ;
+    else if ( ! strcmp ( opt->propName, "scale" ) )
+        capability =  GTK_PRINT_CAPABILITY_SCALE ;
+    else if ( ! strcmp ( opt->propName, "generate-pdf" ) )
+        capability =  GTK_PRINT_CAPABILITY_GENERATE_PDF ;
+    else if ( ! strcmp ( opt->propName, "generate-ps" ) )
+        capability =  GTK_PRINT_CAPABILITY_GENERATE_PS ;
+    else if ( ! strcmp ( opt->propName, "preview" ) )
+        capability = GTK_PRINT_CAPABILITY_PREVIEW ;
+    else if ( ! strcmp ( opt->propName, "number-up" ) )
+        capability =  GTK_PRINT_CAPABILITY_NUMBER_UP ;
+    else if ( ! strcmp ( opt->propName, "number-up-layout" ) )
+        capability =  GTK_PRINT_CAPABILITY_NUMBER_UP_LAYOUT ;
+    else
+        return TCL_ERROR;
 
 	GtkPrintCapabilities tmp = gtk_print_unix_dialog_get_manual_capabilities ( GTK_PRINT_UNIX_DIALOG ( obj ) );
 
