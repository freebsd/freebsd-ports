--- src/mymodel.h.orig	2012-03-09 00:47:45.000000000 -0600
+++ src/mymodel.h	2012-04-29 13:59:45.508571462 -0500
@@ -83,8 +83,8 @@ public:
         bool realMimeTypes;
 
 public slots:
-        void notifyChange();
-        void addWatcher(myModelItem* path);
+        void notifyChange(QString const& path);
+        void addToWatcher(myModelItem* path);
 
 signals:
         void dragDropPaste(const QMimeData * data, QString newPath, QStringList cutList);
@@ -113,9 +113,7 @@ private:
         QString currentRootPath;
         QFileIconProvider* iconFactory;
 
-        int inotifyFD;
-        QSocketNotifier *notifier;
-        QHash<int, QString> watchers;
+        QFileSystemWatcher *watcher;
 };
 
 #endif // MYMODEL_H
