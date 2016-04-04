# Sleuthkit 4.2.0 switched from 100 nano seconds precision to
# 1 nano second precision
# See: https://github.com/log2timeline/dfvfs/issues/116

--- dfvfs/vfs/tsk_file_entry.py.orig	2016-01-11 06:11:52 UTC
+++ dfvfs/vfs/tsk_file_entry.py
@@ -348,6 +348,22 @@ class TSKFileEntry(file_entry.FileEntry)
     stat_object.mtime_nano = getattr(
         tsk_file.info.meta, u'mtime_nano', None)
 
+    # Sleuthkit 4.2.0 switched from 100 nano seconds precision to
+    # 1 nano second precision.
+    if pytsk3.TSK_VERSION_NUM >= 0x040200ff:
+      if stat_object.atime_nano is not None:
+        stat_object.atime_nano /= 100
+      if stat_object.bkup_time_nano is not None:
+        stat_object.bkup_time_nano /= 100
+      if stat_object.ctime_nano is not None:
+        stat_object.ctime_nano /= 100
+      if stat_object.crtime_nano is not None:
+        stat_object.crtime_nano /= 100
+      if stat_object.dtime_nano is not None:
+        stat_object.dtime_nano /= 100
+      if stat_object.mtime_nano is not None:
+        stat_object.mtime_nano /= 100
+
     # Ownership and permissions stat information.
     stat_object.mode = getattr(tsk_file.info.meta, u'mode', None)
     stat_object.uid = getattr(tsk_file.info.meta, u'uid', None)
