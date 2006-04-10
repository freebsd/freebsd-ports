--- ./src/kmldonkey/infodialog.h.orig	Tue Jul 26 13:40:33 2005
+++ ./src/kmldonkey/infodialog.h	Sun Apr  9 13:15:40 2006
@@ -51,7 +51,7 @@
 private:
     int fileno;
 
-    KLineEdit *nameView, *sizeView, *hashView, *formatView,
+    KLineEdit *nameView, *fileNoView, *sizeView, *hashView, *formatView,
 	*totalSizeView, *etaView, *speedView, *networkView,
 	*commentView;
     KListBox *namesView;
