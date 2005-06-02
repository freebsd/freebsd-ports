--- clientgui/ViewProjects.cpp.orig	Sun May 29 03:12:00 2005
+++ clientgui/ViewProjects.cpp	Wed Jun  1 20:44:38 2005
@@ -446,7 +446,7 @@
 
 
 wxString CViewProjects::OnListGetItemText(long item, long column) const {
-    CProject* project     = m_ProjectCache.at(item);
+    CProject* project     = m_ProjectCache[item];
     wxString  strBuffer   = wxEmptyString;
 
     switch(column) {
@@ -546,7 +546,7 @@
 
 
 wxInt32 CViewProjects::UpdateCache(long item, long column, wxString& strNewData) {
-    CProject* project     = m_ProjectCache.at(item);
+    CProject* project     = m_ProjectCache[item];
 
     switch(column) {
         case COLUMN_PROJECT:
