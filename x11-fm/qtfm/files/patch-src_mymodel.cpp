--- src/mymodel.cpp.orig	2012-07-11 18:21:24.302333223 -0500
+++ src/mymodel.cpp	2012-07-11 18:59:06.428956406 -0500
@@ -21,7 +21,6 @@
 
 #include <mainwindow.h>
 #include "mymodel.h"
-#include <sys/inotify.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 
@@ -63,10 +62,8 @@ myModel::myModel(bool realMime)
 
     iconFactory = new QFileIconProvider();
 
-    inotifyFD = inotify_init();
-    notifier = new QSocketNotifier(inotifyFD, QSocketNotifier::Read, this);
-    connect(notifier, SIGNAL(activated(int)), this, SLOT(notifyChange()));
-    connect(&eventTimer,SIGNAL(timeout()),this,SLOT(eventTimeout()));
+    watcher = new QFileSystemWatcher(this);
+    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(notifyChange(QString)));
 
     realMimeTypes = realMime;
 }
@@ -189,62 +186,9 @@ QString myModel::getMimeType(const QMode
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
-        if(eventTimer.isActive())
-        {
-            if(w == lastEventID)
-                eventTimer.start(40);
-            else
-            {
-                eventTimer.stop();
-                notifyProcess(lastEventID);
-                lastEventID = w;
-                eventTimer.start(40);
-            }
-        }
-        else
-        {
-            lastEventID = w;
-            eventTimer.start(40);
-        }
-
-        at += sizeof(inotify_event) + event->len;
-    }
-
-    notifier->setEnabled(1);
-}
-
-//---------------------------------------------------------------------------------------
-void myModel::eventTimeout()
-{
-    notifyProcess(lastEventID);
-    eventTimer.stop();
-}
-
-//---------------------------------------------------------------------------------------
-void myModel::notifyProcess(int eventID)
-{
-    if(watchers.contains(eventID))
-    {
-        myModelItem *parent = rootItem->matchPath(watchers.value(eventID).split(SEPARATOR));
+        myModelItem *parent = rootItem->matchPath(path.split(SEPARATOR));
 
         if(parent)
         {
@@ -265,9 +209,7 @@ void myModel::notifyProcess(int eventID)
                     //must of been deleted, remove from model
                     if(child->fileInfo().isDir())
                     {
-                        int wd = watchers.key(child->absoluteFilePath());
-                        inotify_rm_watch(inotifyFD,wd);
-                        watchers.remove(wd);
+                        watcher->removePath(child->absoluteFilePath());
                     }
                     beginRemoveRows(index(parent->absoluteFilePath()),child->childNumber(),child->childNumber());
                     parent->removeChild(child);
@@ -282,20 +224,19 @@ void myModel::notifyProcess(int eventID)
                 endInsertRows();
             }
         }
-    }
-    else
-    {
-        inotify_rm_watch(inotifyFD,eventID);
-        watchers.remove(eventID);
-    }
+        else
+        {
+                watcher->removePath(path);
+        }
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
@@ -308,7 +249,7 @@ bool myModel::setRootPath(const QString&
 
     myModelItem *item = rootItem->matchPath(path.split(SEPARATOR));
 
-    if(item->watched == 0) addWatcher(item);
+    if(item->watched == 0) addToWatcher(item);
 
     if(item->walked == 0)
     {
@@ -382,10 +323,7 @@ void myModel::refresh()
 {
     myModelItem *item = rootItem->matchPath(QStringList("/"));
 
-    //free all inotify watches
-    foreach(int w, watchers.keys())
-        inotify_rm_watch(inotifyFD,w);
-    watchers.clear();
+    watcher->removePaths(watcher->directories());
 
     beginResetModel();
     item->clearAll();
@@ -840,9 +778,7 @@ bool myModel::remove(const QModelIndex &
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
