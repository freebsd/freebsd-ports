--- gtk-dialog.c.orig	Tue Feb  8 18:31:12 2005
+++ gtk-dialog.c	Thu Apr 21 17:31:33 2005
@@ -156,6 +156,7 @@
     const char *protocol_print;
     GtkWidget *label;
     GtkWidget *dialog;
+    OtrgDialogWaitHandle handle;
 
     p = gaim_find_prpl(protocol);
     protocol_print = (p ? p->info->name : "Unknown");
@@ -166,7 +167,7 @@
 	
     dialog = create_dialog(GAIM_NOTIFY_MSG_INFO, title, primary, secondary,
 	    0, &label);
-    OtrgDialogWaitHandle handle = malloc(sizeof(struct s_OtrgDialogWait));
+    handle = malloc(sizeof(struct s_OtrgDialogWait));
     handle->dialog = dialog;
     handle->label = label;
 
