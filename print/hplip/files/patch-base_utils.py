--- base/utils.py.orig	2022-02-23 07:41:04 UTC
+++ base/utils.py
@@ -139,11 +139,11 @@ for s in EXPECT_WORD_LIST:
 def get_cups_systemgroup_list():
     lis = []
     try:
-        fp=open('/etc/cups/cupsd.conf')
+        fp=open('/usr/local/etc/cups/cupsd.conf')
     except IOError:
         try:
-            if "root" != grp.getgrgid(os.stat('/etc/cups/cupsd.conf').st_gid).gr_name:
-                return [grp.getgrgid(os.stat('/etc/cups/cupsd.conf').st_gid).gr_name]
+            if "root" != grp.getgrgid(os.stat('/usr/local/etc/cups/cupsd.conf').st_gid).gr_name:
+                return [grp.getgrgid(os.stat('/usr/local/etc/cups/cupsd.conf').st_gid).gr_name]
         except OSError:
             return lis
 
