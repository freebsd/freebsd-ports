--- kiltdown/folderview.h.orig	Mon May 14 05:25:23 2001
+++ kiltdown/folderview.h	Wed Dec 25 11:40:29 2002
@@ -118,7 +118,7 @@
      * All objects using Qt extensions such as slots and signals need this.
      */
     Q_OBJECT
-    friend AccountManager;
+    friend class AccountManager;
 
   public:
     FolderView(QWidget *);
