--- kiltdown/mailfolder.cc.orig	Mon May 14 05:25:23 2001
+++ kiltdown/mailfolder.cc	Mon Sep  9 12:04:36 2002
@@ -1353,10 +1353,10 @@
         messagePreview->setFont(QFont(pstr, i));
         localFree(pstr);
     }
-    messagePreview->setUndoEnabled(false);
+    //messagePreview->setUndoEnabled(false);
     messagePreview->setText(body);
     messagePreview->setCursorPosition(0, 0);
-    messagePreview->setUndoEnabled(true);
+    //messagePreview->setUndoEnabled(true);
 
     er = S_OK;
 
