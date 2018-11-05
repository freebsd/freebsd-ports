--- qtoctave/src/generate_menu.cpp.orig	2018-11-05 13:09:19 UTC
+++ qtoctave/src/generate_menu.cpp
@@ -279,7 +279,7 @@ bool GenerateMenu::process_menu_file(QSt
 MenuExtCallBack *GenerateMenu::process_menu_file(QString _file)
 {
 	QFile file(_file);
-	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
+	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return NULL;
 	
 	QString label;
 	MenuExtCallBack *wizard=new MenuExtCallBack();
