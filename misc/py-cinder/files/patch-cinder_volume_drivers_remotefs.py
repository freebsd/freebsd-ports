--- cinder/volume/drivers/remotefs.py.orig	2018-10-09 19:58:17 UTC
+++ cinder/volume/drivers/remotefs.py
@@ -217,9 +217,9 @@ class RemoteFSDriver(driver.BaseVD):
         provisioned_size = 0.0
         for share in self.shares.keys():
             mount_path = self._get_mount_point_for_share(share)
-            out, _ = self._execute('du', '--bytes', '-s', mount_path,
+            out, _ = self._execute('du', '-k', mount_path,
                                    run_as_root=self._execute_as_root)
-            provisioned_size += int(out.split()[0])
+            provisioned_size += int(out.split()[0]) * 1024
         return round(provisioned_size / units.Gi, 2)
 
     def _get_mount_point_base(self):
@@ -892,13 +892,12 @@ class RemoteFSSnapDriverBase(RemoteFSDriver):
         """
         mount_point = self._get_mount_point_for_share(share)
 
-        out, _ = self._execute('df', '--portability', '--block-size', '1',
-                               mount_point,
+        out, _ = self._execute('df', '-k', mount_point,
                                run_as_root=self._execute_as_root)
         out = out.splitlines()[1]
 
-        size = int(out.split()[1])
-        available = int(out.split()[3])
+        size = int(out.split()[1]) * 1024
+        available = int(out.split()[3]) * 1024
 
         return available, size
 
