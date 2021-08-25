--- base/g.py.orig	2022-02-23 07:41:04 UTC
+++ base/g.py
@@ -143,7 +143,7 @@ class ConfigBase(object):
     def write(self):
         if self.filename is not None:
             filename = self.filename
-            if filename.startswith("/root/") or filename.startswith("/etc/"):
+            if filename.startswith("/root/") or filename.startswith("/etc/") or filename.startswith("/usr/local/etc/"):
                 # Don't try writing a file in root's home directory or
                 # the system-wide config file.
                 # See bug #479178.
@@ -182,7 +182,7 @@ class ConfigBase(object):
         
 class SysConfig(ConfigBase):
     def __init__(self):
-        ConfigBase.__init__(self, '/etc/hp/hplip.conf')
+        ConfigBase.__init__(self, '/usr/local/etc/hp/hplip.conf')
 
 
 class State(ConfigBase):
@@ -343,7 +343,7 @@ def check_extension_module_env(ext_mod):
     else :
         python_ver = 2
 
-    for dirpath, dirname, filenames in os.walk('/usr/lib/'):    #find the .so path
+    for dirpath, dirname, filenames in os.walk('/usr/local/lib/'):    #find the .so path
         if ext_mod_so in filenames:
             ext_path = dirpath
             flag = 1
