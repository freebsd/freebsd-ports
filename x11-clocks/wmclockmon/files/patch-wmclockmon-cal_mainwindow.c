--- wmclockmon-cal/mainwindow.c.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-cal/mainwindow.c
@@ -51,7 +51,6 @@ static void show_editor() {
     gtk_widget_hide(calendar);
     gtk_widget_hide(closewindow);
     gtk_widget_grab_default(GTK_WIDGET(cancel));
-    gtk_widget_draw_default(GTK_WIDGET(cancel));
     gtk_widget_grab_focus(GTK_WIDGET(edit));
     gtk_widget_show(text_buttons);
     gtk_widget_show(edit);
@@ -69,7 +68,6 @@ static void hide_editor() {
     gtk_widget_hide(cancel);
     gtk_widget_show(calendar);
     gtk_widget_grab_default(GTK_WIDGET(closewindow));
-    gtk_widget_draw_default(GTK_WIDGET(closewindow));
     gtk_widget_grab_focus(GTK_WIDGET(closewindow));
     gtk_widget_show(closewindow);
 }
@@ -93,13 +91,20 @@ static void load_file(const char *datestr) {
     FILE *file;
     char *filename = get_file(datestr);
 
+    GtkTextIter iter;
+    GtkTextBuffer *buf;
+
+    buf = GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit)));
+    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), &iter);
+    gtk_text_buffer_place_cursor(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), &iter);
+
     if ((file = fopen(filename, "r")) != NULL) {
         while (! feof(file)) {
             char line[MAXSTRLEN + 1];
             bzero(line, MAXSTRLEN + 1);
             fgets(line, MAXSTRLEN, file);
             if (line[0] != 0)
-                gtk_text_insert(GTK_TEXT(edit), NULL, NULL, NULL, line, -1);
+	      gtk_text_buffer_insert(buf, &iter, line, -1);
         }
         fclose(file);
     }
@@ -154,21 +159,14 @@ static void set_buttons_text() {
 
 
 static void editor_flush() {
-    int cont = TRUE;
-
-    while (cont) {
-       cont = gtk_text_backward_delete(GTK_TEXT(edit), 1);
-    }
-    cont = TRUE;
-    while (cont) {
-       cont = gtk_text_forward_delete(GTK_TEXT(edit), 1);
-    }
+    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), "", 0);
 }
 
 
 static void editor_fill(int which) {
     char *filename, *dstr;
     GtkWidget *label;
+    GtkTextIter iter;
 
     switch (which) {
         case UNIQUE: label = label_u; break;
@@ -179,11 +177,10 @@ static void editor_fill(int which) {
     gtk_label_get(GTK_LABEL(label), &dstr);
     strcpy(daystr, dstr);
     to_button(which);
-    gtk_text_freeze(GTK_TEXT(edit));
     editor_flush();
     load_file(daystr);
-    gtk_text_set_point(GTK_TEXT(edit), gtk_text_get_length(GTK_TEXT(edit)));
-    gtk_text_thaw(GTK_TEXT(edit));
+    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), &iter);
+    gtk_text_buffer_place_cursor(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), &iter);
 }
 
 
@@ -225,8 +222,15 @@ static void save_datas() {
     char *dirname  = xmalloc(len + 2);
     struct stat stat_buf;
 
+    GtkTextIter ts, te;
+    gchar *tbuf;
+    int tlen;
+
+    tlen = gtk_text_buffer_get_char_count(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))));
+    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), &ts, &te);
+
     sprintf(dirname, "%s/%s", robust_home(), DEFAULT_CONFIGDIR);
-    if (gtk_text_get_length(GTK_TEXT(edit)) > 0) {
+    if (tlen > 0) {
         if (! ((stat(dirname, &stat_buf) == 0) && S_ISDIR(stat_buf.st_mode)))
             mkdir(dirname, 0755);
 
@@ -235,13 +239,11 @@ static void save_datas() {
             int   year, month, day;
 
             if (file) {
-                int i;
-                for (i = 0 ; i < gtk_text_get_length(GTK_TEXT(edit)) ; i++) {
-                    char t = GTK_TEXT_INDEX(GTK_TEXT(edit), i);
-                    fprintf(file, "%c", t);
-                }
-                fflush(file);
-                fclose(file);
+	      tbuf = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(edit))), &ts, &te, TRUE);
+	      fprintf(file, "%s", tbuf);
+	      g_free(tbuf);
+	      fflush(file);
+	      fclose(file);
             }
             gtk_calendar_get_date(GTK_CALENDAR(calendar), &year, &month, &day);
             gtk_calendar_mark_day(GTK_CALENDAR(calendar), day);
@@ -259,9 +261,7 @@ static void delete_file() {
     gtk_calendar_get_date(GTK_CALENDAR(calendar), &year, &month, &day);
     gtk_calendar_unmark_day(GTK_CALENDAR(calendar), day);
     FREE(filename);
-    gtk_text_freeze(GTK_TEXT(edit));
     editor_flush();
-    gtk_text_thaw(GTK_TEXT(edit));
 }
 
 
@@ -357,10 +357,10 @@ void create_mainwindow() {
             GTK_SIGNAL_FUNC(mark_days), NULL);
     gtk_widget_show(calendar);
 
-    edit = gtk_text_new(NULL, NULL);
-    gtk_text_set_editable(GTK_TEXT(edit), TRUE);
-    gtk_text_set_word_wrap(GTK_TEXT(edit), TRUE);
-    gtk_text_set_line_wrap(GTK_TEXT(edit), TRUE);
+    edit = gtk_text_view_new();
+    gtk_text_view_set_editable(GTK_TEXT_VIEW(edit), TRUE);
+    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(edit), GTK_WRAP_WORD_CHAR);
+
     gtk_box_pack_start(GTK_BOX(main_vbox), edit, TRUE, TRUE, 1);
 
 
@@ -413,7 +413,6 @@ void create_mainwindow() {
     gtk_box_pack_start(GTK_BOX(buttons_hbox), closewindow, TRUE, TRUE, 0);
     GTK_WIDGET_SET_FLAGS(GTK_WIDGET(closewindow), GTK_CAN_DEFAULT);
     gtk_widget_grab_default(GTK_WIDGET(closewindow));
-    gtk_widget_draw_default(GTK_WIDGET(closewindow));
     gtk_widget_show(closewindow);
 
 
