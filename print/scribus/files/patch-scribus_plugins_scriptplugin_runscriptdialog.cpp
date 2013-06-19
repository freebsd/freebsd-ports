--- scribus/plugins/scriptplugin/runscriptdialog.cpp.orig	2008-03-15 04:36:48.000000000 +0400
+++ scribus/plugins/scriptplugin/runscriptdialog.cpp	2013-06-20 00:15:32.226597355 +0400
@@ -10,9 +10,10 @@ for which a new license (GPL+exception) 
 
 QString RunScriptDialog::m_lastScriptDir;
 
-RunScriptDialog::RunScriptDialog(QWidget* parent = 0, bool extEnable = false) :
+RunScriptDialog::RunScriptDialog(QWidget* parent, bool extEnable = false) :
 	QDialog(parent)
 {
+	parent=0;
 	setupUi(this);
 
 	m_extEnable = extEnable;
