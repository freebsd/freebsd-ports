--- clientgui/ViewTransfers.cpp.orig	Sun May 29 03:12:00 2005
+++ clientgui/ViewTransfers.cpp	Wed Jun  1 20:49:11 2005
@@ -226,7 +226,7 @@
 
 
 wxString CViewTransfers::OnListGetItemText(long item, long column) const {
-    CTransfer* transfer   = m_TransferCache.at(item);
+    CTransfer* transfer   = m_TransferCache[item];
     wxString   strBuffer  = wxEmptyString;
 
     switch(column) {
@@ -322,7 +322,7 @@
 
 
 wxInt32 CViewTransfers::UpdateCache(long item, long column, wxString& strNewData) {
-    CTransfer* transfer   = m_TransferCache.at(item);
+    CTransfer* transfer   = m_TransferCache[item];
 
     switch(column) {
         case COLUMN_PROJECT:
