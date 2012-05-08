--- src/mymodel.cpp.orig	2012-03-09 05:00:54.000000000 -0600
+++ src/mymodel.cpp	2012-04-29 16:13:57.725169164 -0500
@@ -21,7 +21,6 @@
 
 #include <mainwindow.h>
 #include "mymodel.h"
-#include <sys/inotify.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 
@@ -63,9 +62,8 @@ myModel::myModel(bool realMime)
 
     iconFactory = new QFileIconProvider();
 
-    inotifyFD = inotify_init();
-    notifier = new QSocketNotifier(inotifyFD, QSocketNotifier::Read, this);
-    connect(notifier, SIGNAL(activated(int)), this, SLOT(notifyChange()));
+    watcher = new QFileSystemWatcher(this);
+    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(notifyChange(QString)));
 
     realMimeTypes = realMime;
 }
@@ -188,28 +186,9 @@ QString myModel::getMimeType(const QMode
 }
 
 //---------------------------------------------------------------------------------------
-void myModel::notifyChange()
+void myModel::notifyChange(QString const& path)
 {
-    notifier->setEnabled(0);
-
-    int buffSize = 0;
-    ioctl(inotifyFD, FIONREAD, (char *) &buffSize);
-
-    QByteArray buffer;
-    buffer.resize(buffSize);
-    read(inotifyFD,buffer.data(),buffSize);
-    const char *at = buffer.data();
-    const char * const end = at + buffSize;
-
-    while (at < end)
-    {
-        const inotify_event *event = reinterpret_cast<const inotify_event *>(at);
-
-        int w = event->wd;
-
-        if(watchers.contains(w))
-        {
-            myModelItem *parent = rootItem->matchPath(watchers.value(w).split(SEPARATOR));
+            myModelItem *parent = rootItem->matchPath(path.split(SEPARATOR));
 
             if(parent)
             {
@@ -230,9 +209,7 @@ void myModel::notifyChange()
                         //must of been deleted, remove from model
                         if(child->fileInfo().isDir())
                         {
-                            int wd = watchers.key(child->absoluteFilePath());
-                            inotify_rm_watch(inotifyFD,wd);
-                            watchers.remove(wd);
+                            watcher->removePath(child->absoluteFilePath());
                         }
                         beginRemoveRows(index(parent->absoluteFilePath()),child->childNumber(),child->childNumber());
                         parent->removeChild(child);
@@ -249,23 +226,17 @@ void myModel::notifyChange()
             }
             else
             {
-                inotify_rm_watch(inotifyFD,w);
-                watchers.remove(w);
+                watcher->removePath(path);
             }
-        }
-
-        at += sizeof(inotify_event) + event->len;
-    }
-
-    notifier->setEnabled(1);
 }
 
 //---------------------------------------------------------------------------------
-void myModel::addWatcher(myModelItem *item)
+void myModel::addToWatcher(myModelItem *item)
 {
     while(item != rootItem)
     {
-        watchers.insert(inotify_add_watch(inotifyFD, item->absoluteFilePath().toLocal8Bit(), IN_MOVE | IN_CREATE | IN_DELETE),item->absoluteFilePath()); //IN_ONESHOT | IN_ALL_EVENTS)
+        if (!watcher->directories().contains(item->absoluteFilePath()))
+            watcher->addPath(item->absoluteFilePath());
         item->watched = 1;
         item = item->parent();
     }
@@ -278,7 +249,7 @@ bool myModel::setRootPath(const QString&
 
     myModelItem *item = rootItem->matchPath(path.split(SEPARATOR));
 
-    if(item->watched == 0) addWatcher(item);
+    if(item->watched == 0) addToWatcher(item);
 
     if(item->walked == 0)
     {
@@ -352,10 +323,7 @@ void myModel::refresh()
 {
     myModelItem *item = rootItem->matchPath(QStringList("/"));
 
-    //free all inotify watches
-    foreach(int w, watchers.keys())
-        inotify_rm_watch(inotifyFD,w);
-    watchers.clear();
+    watcher->removePaths(watcher->directories());
 
     beginResetModel();
     item->clearAll();
@@ -811,9 +779,7 @@ bool myModel::remove(const QModelIndex &
         QFileInfo info(children.at(i));
         if(info.isDir())
         {
-            int wd = watchers.key(info.filePath());
-            inotify_rm_watch(inotifyFD,wd);
-            watchers.remove(wd);
+            watcher->removePath(info.filePath());
             error |= QDir().rmdir(info.filePath());
         }
         else error |= QFile::remove(info.filePath());
