Index: todo_gui.c
diff -u todo_gui.c:1.1.1.1 todo_gui.c:1.1.1.1.4.1
--- todo_gui.c:1.1.1.1	Sun Feb  4 12:58:55 2001
+++ todo_gui.c	Sat Feb 17 17:07:51 2001
@@ -426,12 +426,16 @@
    /*it will show it though.  I allow it. */
    new_todo->description = gtk_editable_get_chars
      (GTK_EDITABLE(todo_text), 0, -1);
+/*   charset_j2p(new_todo->description, 65536); */
    new_todo->note = gtk_editable_get_chars
      (GTK_EDITABLE(todo_text_note), 0, -1);
    if (new_todo->note[0]=='\0') {
       free(new_todo->note);
       new_todo->note=NULL;
    }
+/* else {
+	   charset_j2p(new_todo->note, 65536);
+   }*/
 
    for (i=0; i<NUM_TODO_CAT_ITEMS; i++) {
       if (GTK_IS_WIDGET(todo_cat_menu_item2[i])) {
