--- krename/ProgressDialog.h.orig	Tue Jul  8 11:25:00 2003
+++ krename/ProgressDialog.h	Tue Jul  8 11:25:19 2003
@@ -58,7 +58,7 @@
         void openDest();
 
     private:
-        inline QString count();
+        QString count();
 
     protected:
         QStringList* renamedFiles;
