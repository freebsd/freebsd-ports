--- scribus/plugins/short-words/vlnadialog.cpp.orig	Wed Feb  2 05:02:38 2005
+++ scribus/plugins/short-words/vlnadialog.cpp	Mon Jul  4 13:18:50 2005
@@ -159,7 +159,7 @@
 
 void VlnaDialog::selectAction(int aAction)
 {
-	if (aAction!=0 and aAction!=1 and aAction!=2) {
+	if (aAction!=0 && aAction!=1 && aAction!=2) {
 			aAction = 0;
 	}
 	buttonGroup->setButton(aAction);
