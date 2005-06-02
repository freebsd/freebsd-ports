--- clientgui/ViewResources.cpp.orig	Wed Apr 27 02:55:26 2005
+++ clientgui/ViewResources.cpp	Wed Jun  1 20:47:46 2005
@@ -111,7 +111,7 @@
 
 
 wxString CViewResources::OnListGetItemText(long item, long column) const {
-    CResource* resource   = m_ResourceCache.at(item);
+    CResource* resource   = m_ResourceCache[item];
     wxString   strBuffer  = wxEmptyString;
 
     switch(column)
@@ -178,7 +178,7 @@
 
 
 wxInt32 CViewResources::UpdateCache(long item, long column, wxString& strNewData) {
-    CResource* resource   = m_ResourceCache.at(item);
+    CResource* resource   = m_ResourceCache[item];
 
     switch(column) {
     case COLUMN_PROJECT:
