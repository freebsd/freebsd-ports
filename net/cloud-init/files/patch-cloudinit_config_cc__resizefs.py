--- cloudinit/config/cc_resizefs.py.orig	2020-10-29 12:41:28 UTC
+++ cloudinit/config/cc_resizefs.py
@@ -110,7 +110,7 @@ def _can_skip_resize_ufs(mount_point, devpth):
     for line in dumpfs_res.splitlines():
         if not line.startswith('#'):
             newfs_cmd = shlex.split(line)
-            opt_value = 'O:Ua:s:b:d:e:f:g:h:i:jk:m:o:L:'
+            opt_value = 'O:Ua:s:b:d:e:f:g:h:i:jk:l:m:o:t:L:'
             optlist, _args = getopt.getopt(newfs_cmd[1:], opt_value)
             for o, a in optlist:
                 if o == "-s":
