--- iocage_lib/iocage.py.orig	2026-06-08 13:53:06 UTC
+++ iocage_lib/iocage.py
@@ -53,6 +53,13 @@ from iocage_lib.snapshot import SnapshotListableResour
 from iocage_lib.snapshot import SnapshotListableResource, Snapshot
 
 
+# Workaround for click bugs and incompatible changes introduced
+# in 8.2.x. Once we can upgrade to click 8.4.1, this and all
+# its consumers can be removed, but places using the workaround
+# need to be changed to use flag_value=False instead of
+# is_flag=True (and change default to True).
+CLICK_WORKAROUND=True
+
 class PoolAndDataset:
 
     def get_pool(self):
