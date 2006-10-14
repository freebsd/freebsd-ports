--- src/properties.c.orig	Sat Jul 15 13:54:29 2006
+++ src/properties.c	Sat Jul 15 13:55:03 2006
@@ -499,7 +499,11 @@ main (int argc, char **argv)
 							  _("The \"hald\" service is required but not currently "
 							    "running. Enable the service and rerun this application, "
 							    "or contact your system administrator.\n\n"
+#ifndef __FreeBSD__
 							    "Note: You need Linux kernel 2.6 for volume "
+#else
+							    "Note: You need sysutils/hal installed for volume "
+#endif
 							    "management to work."));
 		
 		gtk_dialog_run (GTK_DIALOG (dialog));
