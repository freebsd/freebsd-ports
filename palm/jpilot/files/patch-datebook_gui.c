Index: datebook_gui.c
diff -u datebook_gui.c:1.1.1.1 datebook_gui.c:1.1.1.1.4.4
--- datebook_gui.c:1.1.1.1	Sun Feb  4 12:58:54 2001
+++ datebook_gui.c	Sat Feb 17 21:48:47 2001
@@ -224,7 +224,6 @@
 
 void cb_date_cats(GtkWidget *widget, gpointer data)
 {
-   unsigned char *buf;
    int size;
    struct AppointmentAppInfo ai;
    int i;
@@ -241,13 +240,7 @@
       return;
    }
 
-   get_app_info("DatebookDB", &buf, &size);
-   jpilot_logf(LOG_DEBUG, "Got datebook app info, size = %d", size);
-   if (size<1) {
-      return;
-   }
-   unpack_AppointmentAppInfo(&ai, buf, size);
-   free(buf);
+   get_datebook_app_info(&ai);
 
    window_date_cats = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 
@@ -268,10 +261,8 @@
    gtk_table_set_col_spacings(GTK_TABLE(table),0);
    gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 0);
 
-   get_pref(PREF_CHAR_SET, &char_set, NULL);
    for (i=0, bit=1; i<16; i++, bit <<= 1) {
       if (ai.category.name[i][0]) {
-         if (char_set == CHAR_SET_JAPANESE)  Sjis2Euc(ai.category.name[i], 65536);
 	 toggle_button[i]=gtk_toggle_button_new_with_label
 	   (ai.category.name[i]);	 
 	 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_button[i]),
@@ -945,7 +936,7 @@
    if (a->note) {
       jpilot_logf(LOG_DEBUG, "text2=[%s]\n",a->note);
    }
-   
+
    /* We won't allow a repeat frequency of less than 1 */
    if ((page != PAGE_NONE) && (a->repeatFrequency < 1)) {
       jpilot_logf(LOG_WARN,
