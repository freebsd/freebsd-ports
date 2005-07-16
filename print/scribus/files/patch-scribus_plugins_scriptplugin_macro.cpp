--- scribus/plugins/scriptplugin/macro.cpp.orig	Sun Jul  3 16:34:04 2005
+++ scribus/plugins/scriptplugin/macro.cpp	Mon Jul  4 13:10:49 2005
@@ -53,7 +53,7 @@
 {
 	assert(!PyErr_Occurred());
 
-	if ((newName == QString::null) or (newName == ""))
+	if ((newName == QString::null) || (newName == ""))
 		qDebug("Macro::Macro() called with NULL or '' name");
 
 	// set the macro name
@@ -344,7 +344,7 @@
 // Must not return with an exception set
 void Macro::setMacroName(QString newName)
 {
-	if ((newName == QString::null) or (newName == ""))
+	if ((newName == QString::null) || (newName == ""))
 	{
 		qDebug("Macro::setMacroName(): called with NULL or '' name");
 		return;
