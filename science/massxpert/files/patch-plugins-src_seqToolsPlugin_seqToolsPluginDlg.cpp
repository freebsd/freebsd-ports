--- plugins-src/seqToolsPlugin/seqToolsPluginDlg.cpp.orig	2012-12-25 21:02:43 UTC
+++ plugins-src/seqToolsPlugin/seqToolsPluginDlg.cpp
@@ -215,7 +215,7 @@ SeqToolsPluginDlg::loadDictionary ()
 
       QStringList stringList = line.split (">", QString::SkipEmptyParts);
       
-      if (!stringList.size () == 2)
+      if (stringList.size () != 2)
 	{
 	  QMessageBox::warning (this,
 				tr ("Sequence Manipulation Tools Plugin"),
