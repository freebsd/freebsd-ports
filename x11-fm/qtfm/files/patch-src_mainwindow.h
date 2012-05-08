--- src/mainwindow.h.orig	2012-03-08 04:46:39.000000000 -0600
+++ src/mainwindow.h	2012-04-29 22:53:06.754026702 -0500
@@ -146,6 +146,15 @@ private:
     void writeSettings();
     void recurseFolder(QString path, QString parent, QStringList *);
 
+    class MountWorker : public QThread
+    {
+        bool ahead;
+    protected:
+        void run();
+    public:
+        void close();
+    };
+
     int zoom;
     int zoomTree;
     int zoomList;
@@ -182,7 +191,11 @@ private:
     bookmarkmodel *modelBookmarks;
     QItemSelectionModel *treeSelectionModel;
     QItemSelectionModel *listSelectionModel;
+#ifdef __FreeBSD__
+    MountWorker *worker;
+#else
     QSocketNotifier *notify;
+#endif
 
     QStringList mounts;
 
