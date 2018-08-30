--- krusader/MountMan/kmountman.cpp.orig	2018-08-30 09:48:03 UTC
+++ krusader/MountMan/kmountman.cpp
@@ -109,18 +109,18 @@ KMountMan::~KMountMan() {}
 
 bool KMountMan::invalidFilesystem(QString type)
 {
-    return (invalid_fs.contains(type) > 0);
+    return (invalid_fs.contains(type));
 }
 
 // this is an ugly hack, but type can actually be a mountpoint. oh well...
 bool KMountMan::nonmountFilesystem(QString type, QString mntPoint)
 {
-    return((nonmount_fs.contains(type) > 0) || (nonmount_fs_mntpoint.contains(mntPoint) > 0));
+    return(bool(nonmount_fs.contains(type)) || bool(nonmount_fs_mntpoint.contains(mntPoint)));
 }
 
 bool KMountMan::networkFilesystem(QString type)
 {
-    return (network_fs.contains(type) > 0);
+    return (network_fs.contains(type));
 }
 
 void KMountMan::mainWindow()
