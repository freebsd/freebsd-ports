--- scribus/plugins/scriptplugin/cmdobj.cpp.orig	Tue Jul 13 05:24:03 2004
+++ scribus/plugins/scriptplugin/cmdobj.cpp	Sun Aug 29 20:02:39 2004
@@ -26,7 +26,7 @@
 															Carrier->doc->Dwidth, Carrier->doc->Dbrush, Carrier->doc->Dpen);
 	Carrier->doc->ActPage->SetRectFrame(Carrier->doc->ActPage->Items.at(i));
 	if (GetUniqueItem(QString(Name)) == NULL)
-		(Name != "") ? Carrier->doc->ActPage->Items.at(i)->AnName = QString(Name) : NULL;
+		(Name != "") ? Carrier->doc->ActPage->Items.at(i)->AnName = QString(Name) : QString::null;
 /*	else
 	{
 		PyErr_SetString(PyExc_Exception, ERROBJ);
