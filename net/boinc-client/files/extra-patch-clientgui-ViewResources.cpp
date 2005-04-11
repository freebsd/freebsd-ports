--- clientgui/ViewResources.cpp.orig	Tue Mar 15 18:44:48 2005
+++ clientgui/ViewResources.cpp	Sun Mar 20 21:31:22 2005
@@ -145,7 +145,7 @@
 
 wxString CViewResources::OnListGetItemText( long item, long column ) const
 {
-    CResource* resource   = m_ResourceCache.at( item );
+    CResource* resource   = m_ResourceCache[item];
     wxString   strBuffer  = wxEmptyString;
 
     switch(column)
@@ -270,7 +270,7 @@
 
 wxInt32 CViewResources::UpdateCache( long item, long column, wxString& strNewData )
 {
-    CResource* resource   = m_ResourceCache.at( item );
+    CResource* resource   = m_ResourceCache[item];
 
     switch(column)
     {
