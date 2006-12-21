--- src/ItemCellPartial.h.orig	Thu Dec 21 13:17:59 2006
+++ src/ItemCellPartial.h	Thu Dec 21 13:18:32 2006
@@ -70,7 +70,7 @@
   ItemCell *ret_Boss();
 
   void WriteSplitInfo(const string& filename);
-  ItemCell::DownloadStatusType ItemCellPartial::Download_Main();
+  ItemCell::DownloadStatusType Download_Main();
 
   SplitStatusType SplitNumberChanged(const string& filename);
 };
