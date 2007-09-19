diff -u -r1.43.2.82 -r1.43.2.83
--- src/toolbar.c	2007/08/30 16:11:57	1.43.2.82
+++ src/toolbar.c	2007/09/18 17:07:51	1.43.2.83
@@ -1643,8 +1643,10 @@
 			GTK_CONTAINER(child)); 								\
 	btn = (GtkWidget *)gchild->data;								\
 	arr = (GtkWidget *)(gchild->next?gchild->next->data:NULL);					\
+	g_list_free(gchild);										\
 	gchild = gtk_container_get_children(GTK_CONTAINER(arr));					\
 	gtk_widget_set_size_request(GTK_WIDGET(gchild->data), 9, -1);					\
+	g_list_free(gchild);										\
 }
 
 #define MAKE_MENU(entries,path,btn) {									\
@@ -2073,6 +2075,7 @@
 		GtkWidget *btn = (GtkWidget *)gchild->data;	\
 		GtkWidget *arr = (GtkWidget *)			\
 			(gchild->next?gchild->next->data:NULL);	\
+		g_list_free(gchild);				\
 		if (GTK_IS_BUTTON(btn))				\
 			in_btn1 = GTK_BUTTON(btn)->in_button;	\
 		if (GTK_IS_BUTTON(arr))				\
@@ -2095,6 +2098,7 @@
 		GtkWidget *btn = (GtkWidget *)gchild->data;	\
 		GtkWidget *arr = (GtkWidget *)			\
 			(gchild->next?gchild->next->data:NULL);	\
+		g_list_free(gchild);				\
 		if (GTK_IS_BUTTON(btn))				\
 			GTK_BUTTON(btn)->in_button = in_btn1;	\
 		if (GTK_IS_BUTTON(arr))				\

