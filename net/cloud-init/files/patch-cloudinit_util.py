--- cloudinit/util.py.orig	2018-08-03 17:34:37 UTC
+++ cloudinit/util.py
@@ -2291,7 +2291,7 @@ def parse_mtab(path):
 
 
 def find_freebsd_part(label_part):
-    if label_part.startswith("/dev/label/"):
+    if label_part.startswith("/dev/gpt/"):
         target_label = label_part[5:]
         (label_part, _err) = subp(['glabel', 'status', '-s'])
         for labels in label_part.split("\n"):
@@ -2300,7 +2300,7 @@ def find_freebsd_part(label_part):
                 label_part = items[2]
                 break
         label_part = str(label_part)
-    return label_part
+    return "/dev/" + label_part
 
 
 def get_path_dev_freebsd(path, mnt_list):
@@ -2324,7 +2324,7 @@ def get_mount_info_freebsd(path):
         result = path_found
     ret = result.split()
     label_part = find_freebsd_part(ret[0])
-    return "/dev/" + label_part, ret[2], ret[1]
+    return label_part, ret[2], ret[1]
 
 
 def get_device_info_from_zpool(zpool):
