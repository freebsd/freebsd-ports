--- cloudinit/config/cc_resizefs.py.orig	2018-08-03 17:33:27 UTC
+++ cloudinit/config/cc_resizefs.py
@@ -81,7 +81,7 @@ def _resize_xfs(mount_point, devpth):
 
 
 def _resize_ufs(mount_point, devpth):
-    return ('growfs', '-y', devpth)
+    return ('growfs', '-y', mount_point)
 
 
 def _resize_zfs(mount_point, devpth):
@@ -110,7 +110,7 @@ def _can_skip_resize_ufs(mount_point, de
     for line in dumpfs_res.splitlines():
         if not line.startswith('#'):
             newfs_cmd = shlex.split(line)
-            opt_value = 'O:Ua:s:b:d:e:f:g:h:i:jk:m:o:'
+            opt_value = 'L:O:Ua:s:b:d:e:f:g:h:i:jk:m:o:'
             optlist, _args = getopt.getopt(newfs_cmd[1:], opt_value)
             for o, a in optlist:
                 if o == "-s":
