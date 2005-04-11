--- clientgui/ViewTransfers.cpp.orig	Tue Mar 15 18:44:48 2005
+++ clientgui/ViewTransfers.cpp	Sun Mar 20 21:32:00 2005
@@ -177,7 +177,7 @@
 
 wxString CViewTransfers::OnListGetItemText(long item, long column) const
 {
-    CTransfer* transfer   = m_TransferCache.at( item );
+    CTransfer* transfer   = m_TransferCache[item];
     wxString   strBuffer  = wxEmptyString;
 
     switch(column)
@@ -372,7 +372,7 @@
 
 wxInt32 CViewTransfers::UpdateCache( long item, long column, wxString& strNewData )
 {
-    CTransfer* transfer   = m_TransferCache.at( item );
+    CTransfer* transfer   = m_TransferCache[item];
 
     switch(column)
     {
