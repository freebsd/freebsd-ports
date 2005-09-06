--- src/reader.cxx.orig	Wed Aug 17 10:21:57 2005
+++ src/reader.cxx	Wed Aug 17 10:22:13 2005
@@ -400,7 +400,7 @@
 // 		ed.Start(readerwin);
 // 	}
 // }
-void updateoutput(int s=0)
+void updateoutput(int s)
 {
 	mail *ml;
 	if (!folderlist->currentfolder()) return;
