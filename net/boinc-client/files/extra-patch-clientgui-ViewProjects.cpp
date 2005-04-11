--- clientgui/ViewProjects.cpp.orig	Tue Mar 15 18:44:48 2005
+++ clientgui/ViewProjects.cpp	Sun Mar 20 21:29:09 2005
@@ -230,7 +230,7 @@
 
 wxString CViewProjects::OnListGetItemText(long item, long column) const 
 {
-    CProject* project     = m_ProjectCache.at( item );
+    CProject* project     = m_ProjectCache[item];
     wxString  strBuffer   = wxEmptyString;
 
     switch(column)
@@ -536,7 +536,7 @@
 
 wxInt32 CViewProjects::UpdateCache( long item, long column, wxString& strNewData )
 {
-    CProject* project     = m_ProjectCache.at( item );
+    CProject* project     = m_ProjectCache[item];
 
     switch(column)
     {
