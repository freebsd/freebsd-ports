--- cloudinit/util.py.orig	2020-10-29 12:40:41 UTC
+++ cloudinit/util.py
@@ -1652,10 +1652,12 @@ def mount_cb(device, callback, data=None, mtype=None,
             mtypes = ["auto"]
     elif platsys.endswith("bsd"):
         if mtypes is None:
-            mtypes = ['ufs', 'cd9660', 'vfat']
+            mtypes = ['ufs', 'cd9660', 'msdos']
         for index, mtype in enumerate(mtypes):
             if mtype == "iso9660":
                 mtypes[index] = "cd9660"
+            if mtype in ["vfat", "msdosfs", "msdos"]:
+                mtypes[index] = "msdos"
     else:
         # we cannot do a smart "auto", so just call 'mount' once with no -t
         mtypes = ['']
