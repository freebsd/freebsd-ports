--- ./kmldonkey/kmldonkey/infodialog.h.orig	2008-07-12 06:04:43.000000000 -0300
+++ ./kmldonkey/kmldonkey/infodialog.h	2008-07-12 06:05:09.000000000 -0300
@@ -51,7 +51,7 @@
 private:
     int fileno;
 
-    KLineEdit *nameView, *sizeView, *hashView, *formatView,
+    KLineEdit *nameView, *fileNoView, *sizeView, *hashView, *formatView,
 	*totalSizeView, *etaView, *speedView, *networkView,
 	*commentView;
     KListBox *namesView;
