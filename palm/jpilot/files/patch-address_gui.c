--- address_gui.c~	2004-05-11 22:33:45.364123000 -0400
+++ address_gui.c	2004-05-11 22:38:37.506140000 -0400
@@ -1427,13 +1427,15 @@
    char number[100];
    char ext[100];
 
-   number[0]=ext[0]='\0';
-   text=data;
 #ifdef ENABLE_GTK2
    GtkTextIter    start_iter;
    GtkTextIter    end_iter;
    GtkTextBuffer *text_buffer;
+#endif
 
+   number[0]=ext[0]='\0';
+   text=data;
+#ifdef ENABLE_GTK2
    text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(text),&start_iter,&end_iter);
    str = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(text),&start_iter,&end_iter,TRUE);
