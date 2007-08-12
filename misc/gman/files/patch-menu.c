--- menu.c.bak	2007-08-12 18:39:59.000000000 +0200
+++ menu.c	2007-08-12 18:44:35.000000000 +0200
@@ -173,32 +173,33 @@
 /*flag = 0 means not to invoke call backs when changing the states of buttons.*/
 void updata_menu_buttons(int flag) 
 {
-	int i,j,k,k2;
-	k = (int)context->get_value("display_section_policy");
+	int i,j;
+	intptr_t k,k2;
+	k = (intptr_t)context->get_value("display_section_policy");
 	if(k>0 && k<=2)
 		if(!((GtkCheckMenuItem*)(section_select[k]))->active){
 			if(!flag) signal_menu_change++;
 			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(section_select[k]),1);
 		}
-	k = (int)context->get_value("display_section");
+	k = (intptr_t)context->get_value("display_section");
 	for (i = 0;i<10;i++)
 		if(!(k&(1<<i)) != !(((GtkCheckMenuItem*)(section_buttons[i]))->active)) {
 			if(!flag) signal_menu_change++;
 			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(section_buttons[i]),k&(1<<i));
 		}
-	k = (int)context->get_value("searching_mode");
+	k = (intptr_t)context->get_value("searching_mode");
 	if(k>0 && k<=1)
 		if(!(((GtkCheckMenuItem*)(searching_mode_buttons[k]))->active)) {
 			if(!flag) signal_menu_change++;
 			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(searching_mode_buttons[k]),1);
 		}
-	k = (int)context->get_value("show_mode");
+	k = (intptr_t)context->get_value("show_mode");
 	if(k>0 && k<=3)
 		if(!(((GtkCheckMenuItem*)(show_mode_buttons[k]))->active)) {
 			if(!flag) signal_menu_change++;
 			gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(show_mode_buttons[k]),1);
 		}
-	k2 = (int)context->get_value("show_status_bar");
+	k2 = (intptr_t)context->get_value("show_status_bar");
 	i = k2&(1<<k);
 	j = (((GtkCheckMenuItem*)(status_bar_button))->active);
 	if((i&&!j) || (!i&&j)) {
@@ -220,10 +221,10 @@
 
 static void updata_widget_show(int flag)
 {	
-	int k,k2;
+	intptr_t k,k2;
 	
-	k = (int)context->get_value("searching_mode");
-	k2 = (int)context->get_value("show_status_bar");
+	k = (intptr_t)context->get_value("searching_mode");
+	k2 = (intptr_t)context->get_value("show_status_bar");
 
 	if(k2&(1<<k)) 
 		gtk_widget_show(hbox_status);
@@ -258,8 +259,8 @@
 	gtk_window_set_title(GTK_WINDOW(window), "Gman");
 	gtk_window_set_policy( GTK_WINDOW( window ), FALSE, TRUE, FALSE );
 	gtk_window_set_default_size(GTK_WINDOW(window),
-								(int)context->get_value("h_size"),
-								(int)context->get_value("v_size"));
+								(intptr_t)context->get_value("h_size"),
+								(intptr_t)context->get_value("v_size"));
 	
 	gtk_widget_set_usize(GTK_WIDGET(window),200,150);
 	main_vbox = gtk_vbox_new(FALSE, 1);
@@ -443,14 +444,14 @@
 
 static int section_policy_callback(GtkWidget *w, gpointer data) {
 	//	static int signal;
-	int k,k2;
-	k2 = (int) data;
+	intptr_t k,k2;
+	k2 = (intptr_t) data;
 	if(!((GtkCheckMenuItem*)(section_select[k2]))->active) return 1;
 	//	g_message("Hello, World! %x\n signal = %d",data,signal_menu_change);
 	if(signal_menu_change>0) {signal_menu_change--;return 1;}
 	//if(!signal) {signal++;return 1;}
 	//signal--;
-	k = (int) context->get_value("display_section_policy");
+	k = (intptr_t) context->get_value("display_section_policy");
 	if(k == k2) return 1;
 	pthread_mutex_lock(&context_lock);
 	context->set_value("display_section_policy","int",(void*)k2);
@@ -461,12 +462,12 @@
 }
 
 static int section_select_callback(GtkWidget *w, gpointer data) {
-	int var;
+	intptr_t var;
 	if(signal_menu_change>0) {signal_menu_change--;return 1;}
 
 	pthread_mutex_lock(&context_lock);
-	var = (int)context->get_value("display_section");
-	var ^= (int)data;
+	var = (intptr_t)context->get_value("display_section");
+	var ^= (intptr_t)data;
 	context->set_value("display_section","int",(void*)var);
 	if (context->get_value("display_section_policy")) {
 		task_set_active(task_extract_man_data);
@@ -496,7 +497,7 @@
 	}
 	//	context->save(stdout,"automatically made by Gman");
 	
-	gtk_exit((int)data);
+	gtk_exit((intptr_t)data);
 }
 
 static int window_resize_callback(GtkWidget *w, GtkAllocation * size, gpointer data)
@@ -573,10 +574,10 @@
 
 static int status_bar_callback (GtkWidget *widget, gpointer   data)
 {
-	int k,k2;
+	intptr_t k,k2;
 	if(signal_menu_change>0) {signal_menu_change--;return 1;}
-	k2 = (int) context->get_value("show_status_bar");
-	k = (int) context->get_value("searching_mode");
+	k2 = (intptr_t) context->get_value("show_status_bar");
+	k = (intptr_t) context->get_value("searching_mode");
 	if(((GtkCheckMenuItem*)(status_bar_button))->active) k2 = k2 | (1<<k);
 	else k2 = k2 & ~(1<<k);
 	pthread_mutex_lock(&context_lock);
@@ -588,13 +589,13 @@
 
 static int search_mode_callback (GtkWidget *widget, gpointer   data)
 {
-	int k,k2;
-	k2 = (int) data;
+	intptr_t k,k2;
+	k2 = (intptr_t) data;
 	if(!((GtkCheckMenuItem*)(searching_mode_buttons[k2]))->active) return 1;
 	if(signal_menu_change>0) {signal_menu_change--;return 1;}
 	//if(!signal) {signal++;return 1;}
 	//signal--;
-	k = (int) context->get_value("searching_mode");
+	k = (intptr_t) context->get_value("searching_mode");
 	if(k == k2) return 1;
 	pthread_mutex_lock(&context_lock);
 	context->set_value("searching_mode","int",(void*)k2);
@@ -606,13 +607,13 @@
 
 static int show_mode_callback (GtkWidget *widget, gpointer   data)
 {
-	int k,k2;
-	k2 = (int) data;
+	intptr_t k,k2;
+	k2 = (intptr_t) data;
 	if(!((GtkCheckMenuItem*)(show_mode_buttons[k2]))->active) return 1;
 	if(signal_menu_change>0) {signal_menu_change--;return 1;}
 	//if(!signal) {signal++;return 1;}
 	//signal--;
-	k = (int) context->get_value("show_mode");
+	k = (intptr_t) context->get_value("show_mode");
 	if(k == k2) return 1;
 	pthread_mutex_lock(&context_lock);
 	context->set_value("show_mode","int",(void*)k2);
@@ -638,7 +639,7 @@
 
 static int button_clicked_callback(GtkWidget * w,gpointer data)
 {
-	int i = (int) data;
+	intptr_t i = (intptr_t) data;
 	switch (i) {
 	case 1: task_set_stop(task_key_word_search);break;
 	case 2: task_set_active(task_key_word_search);break;
