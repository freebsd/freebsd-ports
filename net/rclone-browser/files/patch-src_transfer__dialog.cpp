--- src/transfer_dialog.cpp.orig	2017-03-11 22:16:36 UTC
+++ src/transfer_dialog.cpp
@@ -131,7 +131,7 @@ QString TransferDialog::getMode() const
         return "Sync";
     }
 
-    return QString::null;
+    return QString();
 }
 
 QString TransferDialog::getSource() const
