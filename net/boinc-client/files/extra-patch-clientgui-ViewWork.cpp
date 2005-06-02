--- clientgui/ViewWork.cpp.orig	Sun May 29 03:12:00 2005
+++ clientgui/ViewWork.cpp	Wed Jun  1 20:50:34 2005
@@ -302,7 +302,7 @@
 
 
 wxString CViewWork::OnListGetItemText(long item, long column) const {
-    CWork*    work      = m_WorkCache.at(item);
+    CWork*    work      = m_WorkCache[item];
     wxString  strBuffer = wxEmptyString;
 
     switch(column) {
@@ -404,7 +404,7 @@
 
 
 wxInt32 CViewWork::UpdateCache(long item, long column, wxString& strNewData) {
-    CWork* work   = m_WorkCache.at(item);
+    CWork* work   = m_WorkCache[item];
 
     switch(column) {
         case COLUMN_PROJECT:
@@ -497,10 +497,7 @@
     pDoc->GetWorkApplicationName(item, strTempName);
     pDoc->GetWorkApplicationVersion(item, iBuffer);
 
-    wxString strLocale = setlocale(LC_NUMERIC, NULL);
-    setlocale(LC_NUMERIC, "C");
     strBuffer.Printf(wxT("%s %.2f"), strTempName.c_str(), iBuffer/100.0);
-    setlocale(LC_NUMERIC, strLocale.c_str());
 
     return 0;
 }
