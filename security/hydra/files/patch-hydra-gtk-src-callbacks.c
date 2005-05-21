--- hydra-gtk/src/callbacks.c.realorig	Tue Jun  8 00:33:18 2004
+++ hydra-gtk/src/callbacks.c	Sat May 21 14:20:53 2005
@@ -69,21 +69,6 @@
 
 	options[0] = HYDRA_BIN;
 
-	/* get the target, or target list */
-	widget = lookup_widget(GTK_WIDGET(wndMain), "radioTarget1");
-	if ( gtk_toggle_button_get_active((GtkToggleButton *) widget) ){	
-		widget = lookup_widget(GTK_WIDGET(wndMain), "entTarget");
-		options[i++] = (char *) gtk_entry_get_text((GtkEntry *) widget);
-	} else {
-		options[i++] = "-M";
-		widget = lookup_widget(GTK_WIDGET(wndMain), "entTargetFile");
-		options[i++] = (char *) gtk_entry_get_text((GtkEntry *) widget);
-	}
-
-	/* get the service */
-	widget = lookup_widget(GTK_WIDGET(wndMain), "entProtocol");
-	options[i++] = (char *) gtk_entry_get_text((GtkEntry *) widget);
-	
 	/* get the port */
 	widget = lookup_widget(GTK_WIDGET(wndMain), "spnPort");
 	j = gtk_spin_button_get_value_as_int((GtkSpinButton *) widget);
@@ -307,6 +292,21 @@
 		}
 	}		
 
+	/* get the target, or target list */
+	widget = lookup_widget(GTK_WIDGET(wndMain), "radioTarget1");
+	if ( gtk_toggle_button_get_active((GtkToggleButton *) widget) ){	
+		widget = lookup_widget(GTK_WIDGET(wndMain), "entTarget");
+		options[i++] = (char *) gtk_entry_get_text((GtkEntry *) widget);
+	} else {
+		options[i++] = "-M";
+		widget = lookup_widget(GTK_WIDGET(wndMain), "entTargetFile");
+		options[i++] = (char *) gtk_entry_get_text((GtkEntry *) widget);
+	}
+
+	/* get the service */
+	widget = lookup_widget(GTK_WIDGET(wndMain), "entProtocol");
+	options[i++] = (char *) gtk_entry_get_text((GtkEntry *) widget);
+	
 	options[i] = NULL;
 	return i;
 }
@@ -472,8 +472,8 @@
 int *popen_re_unbuffered(char *command) {
 	static int p_r[2] = {-1, -1}, p_e[2] = {-1, -1};
 	static int *pfd = NULL;
-	hydra_pid = 0;
 	char *options[128];
+	hydra_pid = 0;
 
 	update_statusbar();
 
@@ -494,6 +494,7 @@
 		g_warning("popen_rw_unbuffered: Error forking!");
 		return NULL;
 	} else if (hydra_pid == 0) { /* child */
+		int k;
 		if (setpgid(getpid(), getpid()) < 0)
 			g_warning("popen_rw_unbuffered: setpgid() failed");
 		if (close(p_r[0]) < 0)
@@ -517,7 +518,6 @@
 		execv(HYDRA_BIN, options);
 
 		g_warning("%s %i: popen_rw_unbuffered: execv() returned", __FILE__, __LINE__);
-		int k;
 		for ( k = 0; options[k] != NULL; k++ ){
 			g_warning(options[k]);
 		}
@@ -669,8 +669,9 @@
 on_chkColon_toggled                    (GtkToggleButton *togglebutton,
                                         gpointer         user_data)
 {
-	GtkWidget *user =  lookup_widget(GTK_WIDGET(wndMain), "frmUsername");;	
-	GtkWidget *pass =  lookup_widget(GTK_WIDGET(wndMain), "frmPass");
+	GtkWidget *user, *pass;
+	user =  lookup_widget(GTK_WIDGET(wndMain), "frmUsername");;	
+	pass =  lookup_widget(GTK_WIDGET(wndMain), "frmPass");
 
 	if (gtk_toggle_button_get_active(togglebutton)){
 		gtk_widget_set_sensitive(user, FALSE);
