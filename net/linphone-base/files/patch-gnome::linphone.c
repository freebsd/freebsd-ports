--- gnome/linphone.c.orig	Fri Mar 11 00:38:56 2005
+++ gnome/linphone.c	Wed Mar 23 19:33:00 2005
@@ -255,9 +255,10 @@
 	LinphoneCore *lc=get_core();
 	GList *elem=linphone_core_get_proxy_config_list(lc);
 	LinphoneProxyConfig *cfg=NULL;
-	linphone_core_get_default_proxy(lc,&cfg);
 	GtkWidget *combo;
-	GtkWidget *hbox=lookup_widget(window,"proxy_hbox");
+	GtkWidget *hbox;
+	linphone_core_get_default_proxy(lc,&cfg);
+	hbox=lookup_widget(window,"proxy_hbox");
 	if (elem==NULL){
 		gtk_widget_hide(hbox);
 		return;
