diff -ruN bibletime/frontend/searchdialog/csearchdialog.cpp bibletime/frontend/searchdialog/csearchdialog.cpp
--- bibletime/frontend/searchdialog/csearchdialog.cpp	Sat Apr 20 02:25:39 2002
+++ bibletime/frontend/searchdialog/csearchdialog.cpp	Thu Jun 20 09:24:54 2002
@@ -114,7 +114,7 @@
 }
 
 void CSearchDialog::setModuleList(ListCSwordModuleInfo& list) {
-	if (m_moduleList != list)
+	if (! (m_moduleList == list) )
 		m_moduleList = list; //copy the items of "list"
 	
 	m_moduleChooser->blockSignals(true);
