--- src/main.c.orig	Mon Oct 31 07:54:17 2005
+++ src/main.c	Mon Oct 31 23:53:19 2005
@@ -1229,9 +1229,9 @@
 
 static void overwrite_yes_cb(GtkWidget *widget, gpointer data)
 {
-	destroy_yesno_dialog(widget);
-	
 	char *filename = get_filename(data, ".en");
+
+	destroy_yesno_dialog(widget);
 	
 	if (!gtk_term_save(term,filename)) {
 		char *txt = g_strdup_printf("\nI could not save the notebook to the file\n%s\n",filename);
@@ -1262,9 +1262,9 @@
 
 static void overwrite_yes_open_cb(GtkWidget *widget, gpointer data)
 {
-	destroy_yesno_dialog(widget);
-	
 	char *filename = get_filename(data, ".en");
+	
+	destroy_yesno_dialog(widget);
 		
 	if (gtk_term_save(term,filename)) {
 		gtk_widget_destroy((GtkWidget*)data);
@@ -1318,9 +1318,9 @@
 
 static void overwrite_yes_quit_cb(GtkWidget *widget, gpointer data)
 {
-	destroy_yesno_dialog(widget);
-	
 	char *filename = get_filename(data, ".en");
+	
+	destroy_yesno_dialog(widget);
 		
 	if (gtk_term_save(term,filename)){
 		gtk_widget_destroy((GtkWidget*)data);
@@ -1763,8 +1763,8 @@
 {
 	GtkTerm *t = GTK_TERM(term);
 	if (t->editing) {
-		if (!strlen(efname)) return;
 		char *text = g_strdup_printf("load \"%s\"", efname);
+		if (!strlen(efname)) return;
 		
 		if (t->pos<=e_get_text_length(t->a,t->cur))
 			e_remove_text(t->a,t->cur,1,e_get_text_length(t->a,t->cur)-1);
@@ -1780,11 +1780,6 @@
 
 static void editor(void)
 {
-  	if (editordialog) {
-		gdk_window_raise(editordialog->window);
-		return;
-	}
-	
 	GtkWidget *vbox;
   	GtkWidget *toolbar;
   	GtkWidget *button;
@@ -1796,6 +1791,11 @@
   	PangoFontDescription *pfd;
 	GtkIconSize tmp_toolbar_icon_size;
 	
+  	if (editordialog) {
+		gdk_window_raise(editordialog->window);
+		return;
+	}
+	
   	editordialog = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 //  gtk_window_set_transient_for(GTK_WINDOW(editordialog),GTK_WINDOW(term_window));
 //	gtk_window_set_modal(GTK_WINDOW(editordialog),TRUE);
@@ -2002,8 +2002,9 @@
 
 static void overwrite_yes_dndopen_cb(GtkWidget *widget, gpointer data)
 {
-	destroy_yesno_dialog(widget);
 	char *filename = get_filename(data, ".en");
+
+	destroy_yesno_dialog(widget);
 		
 	if (gtk_term_save(term,filename)) {
 		gtk_widget_destroy((GtkWidget*)data);
@@ -2325,9 +2326,9 @@
 
 static void no_demo_cb(GtkWidget *widget, gpointer data)
 {
-	destroy_yesno_dialog(widget);
-	
 	gchar *s;
+	
+	destroy_yesno_dialog(widget);
 	s = g_strconcat(INSTALL_DIR,"/share/euler/progs/",demo_name,NULL);
 	gtk_term_load(term,s);
 	g_free(s);
