--- clientgui/ViewWork.cpp.orig	Tue Mar 15 18:44:48 2005
+++ clientgui/ViewWork.cpp	Sun Mar 20 21:35:22 2005
@@ -190,7 +190,7 @@
 
 wxString CViewWork::OnListGetItemText( long item, long column ) const
 {
-    CWork*    work      = m_WorkCache.at( item );
+    CWork*    work      = m_WorkCache[item];
     wxString  strBuffer = wxEmptyString;
 
     switch(column)
@@ -436,7 +436,7 @@
 
 wxInt32 CViewWork::UpdateCache( long item, long column, wxString& strNewData )
 {
-    CWork* work   = m_WorkCache.at( item );
+    CWork* work   = m_WorkCache[item];
 
     switch(column)
     {
@@ -589,10 +589,7 @@
     pDoc->GetWorkApplicationName(item, strTempName);
     pDoc->GetWorkApplicationVersion(item, iBuffer);
 
-    wxString strLocale = setlocale(LC_NUMERIC, NULL);
-    setlocale(LC_NUMERIC, "C");
     strBuffer.Printf(wxT("%s %.2f"), strTempName.c_str(), iBuffer/100.0);
-    setlocale(LC_NUMERIC, strLocale.c_str());
 
     return 0;
 }
