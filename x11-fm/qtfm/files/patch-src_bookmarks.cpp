--- src/bookmarks.cpp.orig	2012-07-11 18:10:56.065528820 -0500
+++ src/bookmarks.cpp	2012-07-11 18:19:42.041677562 -0500
@@ -22,6 +22,11 @@
 #ifndef BOOKMARKS_CPP
 #define BOOKMARKS_CPP
 
+#ifdef __FreeBSD__
+#include <sys/event.h>
+#include <sys/mount.h>
+#endif
+
 #include <QtGui>
 #include "bookmarkmodel.h"
 #include "icondlg.h"
@@ -80,44 +85,74 @@ void MainWindow::mountWatcherTriggered()
 }
 
 //---------------------------------------------------------------------------
+#ifdef __FreeBSD__
+void MainWindow::MountWorker::run()
+{
+
+    ahead = 1;
+    int kq = kqueue();
+    struct kevent ki[1];
+    struct timespec to[1] = {{ 0, 100000 }};
+
+    EV_SET(ki, 0, EVFILT_FS, EV_ADD, VQ_MOUNT | VQ_UNMOUNT, 0, 0);
+    kevent(kq, ki, 1, NULL, 0, NULL);
+
+    while (ahead) {
+        switch (kevent(kq, NULL, 0, ki, 1, to)) {
+        case -1:
+            ::perror("kevent");
+            break;
+        case 0:
+            continue;
+        default:
+            ((MainWindow *)parent())->MainWindow::autoBookmarkMounts();
+        }
+    }
+    ::close(kq);
+}
+
+void MainWindow::MountWorker::close()
+{
+    ahead = 0;
+    wait();
+}
+#endif
+
+//---------------------------------------------------------------------------
 void MainWindow::autoBookmarkMounts()
 {
     QList<QStandardItem *> theBookmarks = modelBookmarks->findItems("*",Qt::MatchWildcard);
 
     QStringList autoBookmarks;
 
+    size_t mntsize;
+    struct statfs *mnt, *mntbuf;
+
     foreach(QStandardItem *item, theBookmarks)
     {
         if(item->data(34).toString() == "1")		    //is an automount
             autoBookmarks.append(item->data(32).toString());
     }
 
-    QStringList mtabMounts;
-    QFile mtab("/etc/mtab");
-    mtab.open(QFile::ReadOnly);
-    QTextStream stream(&mtab);
-    do mtabMounts.append(stream.readLine());
-    while (!stream.atEnd());
-    mtab.close();
+    mntsize = getmntinfo(&mntbuf, MNT_NOWAIT);
 
-    QStringList sysMounts = QStringList() << "/dev" << "/sys" << "/pro" << "/tmp" << "/run";
     QStringList dontShowList = settings->value("hideBookmarks",0).toStringList();
     mounts.clear();
 
-    foreach(QString item, mtabMounts)
-	if(!sysMounts.contains(item.split(" ").at(1).left(4)))
+    for (mnt = mntbuf; mntsize > 0; mntsize--, mnt++)
+        // XXX zpool name does not start with /
+        if (mnt->f_mntfromname[0] == '/' or !strcmp(mnt->f_fstypename, "zfs"))
         {
-            QString path = item.split(" ").at(1);
-            path.replace("\\040"," ");
-
-            mounts.append(path);
-            if(!dontShowList.contains(path))
-                if(!autoBookmarks.contains(path))	    //add a new auto bookmark if it doesn't exist
+            mounts.append(mnt->f_mntonname);
+            if(!dontShowList.contains(mnt->f_mntonname))
+                //add a new auto bookmark if it doesn't exist
+                if(!autoBookmarks.contains(mnt->f_mntonname))
                 {
-			autoBookmarks.append(path);
-                    if(item.split(" ").at(2) == "iso9660") modelBookmarks->addBookmark(path,path,"1","drive-optical");
-                    else if(item.split(" ").at(2).contains("fat")) modelBookmarks->addBookmark(path,path,"1","drive-removable-media");
-                    else modelBookmarks->addBookmark(path,path,"1","drive-harddisk");
+                    if(strstr(mnt->f_fstypename, "9660"))
+                        modelBookmarks->addBookmark(mnt->f_mntonname,mnt->f_mntonname,"1","drive-optical");
+                    else if(strstr(mnt->f_fstypename, "fat"))
+                        modelBookmarks->addBookmark(mnt->f_mntonname,mnt->f_mntonname,"1","drive-removable-media");
+                    else modelBookmarks->addBookmark(mnt->f_mntonname,mnt->f_mntonname,"1","drive-harddisk");
                 }
         }
 
