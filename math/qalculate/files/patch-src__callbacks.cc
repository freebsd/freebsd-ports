--- src/callbacks.cc.orig
+++ src/callbacks.cc
@@ -346,7 +346,7 @@
 			it->sort();
 		}
 	}
-	bool operator < (tree_struct &s1) const {
+	bool operator < (const tree_struct &s1) const {
 		return item < s1.item;	
 	}	
 };
@@ -388,12 +388,12 @@
 }
 
 void show_message(const gchar *text, GtkWidget *win) {
-	GtkWidget *edialog = gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, text);
+	GtkWidget *edialog = gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "%s", text);
 	gtk_dialog_run(GTK_DIALOG(edialog));
 	gtk_widget_destroy(edialog);
 }
 bool ask_question(const gchar *text, GtkWidget *win) {
-	GtkWidget *edialog = gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_YES_NO, text);
+	GtkWidget *edialog = gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_YES_NO, "%s", text);
 	int question_answer = gtk_dialog_run(GTK_DIALOG(edialog));
 	gtk_widget_destroy(edialog);
 	return question_answer == GTK_RESPONSE_YES;
@@ -654,6 +654,7 @@
 					GTK_DIALOG_DESTROY_WITH_PARENT,
 					GTK_MESSAGE_INFO,
 					GTK_BUTTONS_CLOSE,
+					"%s",
 					CALCULATOR->message()->message().c_str());
 			gtk_dialog_run(GTK_DIALOG(edialog));
 			gtk_widget_destroy(edialog);
@@ -667,6 +668,7 @@
 					GTK_DIALOG_DESTROY_WITH_PARENT,
 					GTK_MESSAGE_ERROR,
 					GTK_BUTTONS_CLOSE,
+					"%s",
 					str.c_str());
 		} else {
 			edialog = gtk_message_dialog_new(
@@ -674,6 +676,7 @@
 					GTK_DIALOG_DESTROY_WITH_PARENT,
 					GTK_MESSAGE_WARNING,
 					GTK_BUTTONS_CLOSE,
+					"%s",
 					str.c_str());
 		}
 
@@ -9405,6 +9408,7 @@
 	} else {
 		first_time = true;
 	}
+	fclose(file);
 	if(show_keypad) show_history = false;
 	set_saved_mode();
 
