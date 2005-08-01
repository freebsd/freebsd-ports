--- libgnomeui/gnome-authentication-manager.c.orig	Mon Aug  1 03:34:03 2005
+++ libgnomeui/gnome-authentication-manager.c	Mon Aug  1 03:36:29 2005
@@ -849,7 +849,11 @@
 	info->response = response;
 	info->response_data = response_data;
 
+	GDK_THREADS_ENTER ();
+
 	present_question_dialog_nonblocking (info);
+
+	GDK_THREADS_LEAVE ();
 }
 
 static void /* GnomeVFSModuleCallback */
@@ -870,11 +874,15 @@
 	in_real = (GnomeVFSModuleCallbackQuestionIn *)in;
 	out_real = (GnomeVFSModuleCallbackQuestionOut *)out;
 	
+	GDK_THREADS_ENTER ();
+
 	out_real->answer = -1; /* Set a default value */
 	dialog = create_question_dialog (in_real->primary_message, in_real->secondary_message, in_real->choices);
 	out_real->answer = gtk_dialog_run (GTK_DIALOG(dialog));
 
 	gtk_widget_destroy (GTK_WIDGET (dialog));
+
+	GDK_THREADS_LEAVE ();
 }
 
 
