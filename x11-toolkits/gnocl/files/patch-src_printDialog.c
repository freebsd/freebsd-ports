--- src/printDialog.c.orig	2013-01-31 10:52:21.000000000 +0100
+++ src/printDialog.c	2013-02-01 14:25:27.000000000 +0100
@@ -20,6 +20,7 @@
 #include "string.h"
 #include <assert.h>
 #include <gtk-unix-print-2.0/gtk/gtkprinter.h>
+#include <gtk-unix-print-2.0/gtk/gtkprintunixdialog.h>
 
 /* static declarations */
 static int gnoclOptPageSetup ( Tcl_Interp *interp, GnoclOption *opt, GObject *obj, Tcl_Obj **ret );
@@ -63,67 +64,28 @@
 
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
+	if ( ! strcmp ( opt->propName, "page-set" ) )
+		capability = GTK_PRINT_CAPABILITY_PAGE_SET;
+	else if ( ! strcmp ( opt->propName, "copies" ) )
+		capability = GTK_PRINT_CAPABILITY_COPIES;
+	else if ( ! strcmp ( opt->propName, "collate" ) )
+		capability =  GTK_PRINT_CAPABILITY_COLLATE;
+	else if ( ! strcmp ( opt->propName, "reverse" ) )
+		capability =  GTK_PRINT_CAPABILITY_REVERSE ;
+	else if ( ! strcmp ( opt->propName, "scale" ) )
+		capability =  GTK_PRINT_CAPABILITY_SCALE ;
+	else if ( ! strcmp ( opt->propName, "generate-pdf" ) )
+		capability =  GTK_PRINT_CAPABILITY_GENERATE_PDF ;
+	else if ( ! strcmp ( opt->propName, "generate-ps" ) )
+		capability =  GTK_PRINT_CAPABILITY_GENERATE_PS ;
+	else if ( ! strcmp ( opt->propName, "preview" ) )
+		capability = GTK_PRINT_CAPABILITY_PREVIEW ;
+	else if ( ! strcmp ( opt->propName, "number-up" ) )
+		capability =  GTK_PRINT_CAPABILITY_NUMBER_UP ;
+	else if ( ! strcmp ( opt->propName, "number-up-layout" ) )
+		capability =  GTK_PRINT_CAPABILITY_NUMBER_UP_LAYOUT ;
+	else 
+		return TCL_ERROR;
 
 	GtkPrintCapabilities tmp = gtk_print_unix_dialog_get_manual_capabilities ( GTK_PRINT_UNIX_DIALOG ( obj ) );
 
