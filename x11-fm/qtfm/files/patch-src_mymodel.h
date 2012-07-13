--- src/mymodel.h.orig	2012-07-11 19:01:59.919235618 -0500
+++ src/mymodel.h	2012-07-11 19:03:41.246365243 -0500
@@ -84,10 +84,8 @@ public:
         bool realMimeTypes;
 
 public slots:
-        void notifyChange();
-        void notifyProcess(int eventID);
-        void eventTimeout();
-        void addWatcher(myModelItem* path);
+        void notifyChange(QString const& path);
+        void addToWatcher(myModelItem* path);
 
 signals:
         void dragDropPaste(const QMimeData * data, QString newPath, QStringList cutList);
@@ -116,11 +114,7 @@ private:
         QString currentRootPath;
         QFileIconProvider* iconFactory;
 
-        int inotifyFD;
-        QSocketNotifier *notifier;
-        QHash<int, QString> watchers;
-        QTimer eventTimer;
-        int lastEventID;
+        QFileSystemWatcher *watcher;
 };
 
 #endif // MYMODEL_H
