--- src/messageview.c.orig	Wed Aug 18 03:23:29 2004
+++ src/messageview.c	Wed Aug 18 03:37:58 2004
@@ -80,7 +80,9 @@
 	imageview->messageview = messageview;
 
 	htmlview = htmlview_create();
-	htmlview->messageview = messageview;
+	if(htmlview) {
+	    htmlview->messageview = messageview;
+	}
 
 	mimeview = mimeview_create();
 	mimeview->textview = textview;
@@ -91,7 +93,9 @@
 	/* to remove without destroyed */
 	gtk_widget_ref(*(GtkWidget **)textview);
 	gtk_widget_ref(*(GtkWidget **)imageview);
-	gtk_widget_ref(*(GtkWidget **)htmlview);
+	if(htmlview) {
+	    gtk_widget_ref(*(GtkWidget **)htmlview);
+	}
 	gtk_widget_ref(*(GtkWidget **)mimeview);
 
 	paned = gtk_vpaned_new();
@@ -152,7 +156,9 @@
 	gtk_paned_add2(GTK_PANED(messageview->paned), *(GtkWidget **)textview);
 #endif
 
-	htmlview_init(messageview->htmlview);
+	if(messageview->htmlview) {
+	    htmlview_init(messageview->htmlview);
+	}
 	mimeview_init(messageview->mimeview);
 	textview_init(messageview->textview);
 	imageview_init(messageview->imageview);
@@ -267,17 +273,21 @@
 	GtkWidget *textview  = *(GtkWidget **)messageview->textview;
 	GtkWidget *imageview = *(GtkWidget **)messageview->imageview;
 	GtkWidget *mimeview  = *(GtkWidget **)messageview->mimeview;
-	GtkWidget *htmlview = *(GtkWidget **)messageview->htmlview;
+
+	if(messageview->htmlview) {
+	    GtkWidget *htmlview = *(GtkWidget **)messageview->htmlview;
+	    htmlview_destroy(messageview->htmlview);
+	    gtk_widget_destroy(htmlview);
+	}
+
 	textview_destroy(messageview->textview);
 	imageview_destroy(messageview->imageview);
-	htmlview_destroy(messageview->htmlview);
 	mimeview_destroy(messageview->mimeview);
 
 	g_free(messageview);
 
 	gtk_widget_unref(textview);
 	gtk_widget_unref(imageview);
-	gtk_widget_unref(htmlview);
 	gtk_widget_unref(mimeview);
 }
 
