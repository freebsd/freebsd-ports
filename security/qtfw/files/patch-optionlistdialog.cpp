--- optionlistdialog.cpp.orig	Fri Feb 14 13:45:36 2003
+++ optionlistdialog.cpp	Fri Feb 14 13:46:06 2003
@@ -15,7 +15,7 @@
 {
 }
 
-OptionListDialog::OptionListDialog(QString * items,int numItems, QString selected_item,QWidget* parent = 0, const char* name = 0)
+OptionListDialog::OptionListDialog(QString * items,int numItems, QString selected_item,QWidget* parent, const char* name)
 	: QDialog( parent, name, TRUE, 0 )	
 {
 	if ( !name )
@@ -79,7 +79,7 @@
 {
 }
 
-IcmptypeListDialog::IcmptypeListDialog(_icmpcode * items,int numItems, QString selected_item,QWidget* parent = 0, const char* name = 0)
+IcmptypeListDialog::IcmptypeListDialog(_icmpcode * items,int numItems, QString selected_item,QWidget* parent, const char* name)
 	: QDialog( parent, name, TRUE, 0 )	
 {
 	if ( !name )
