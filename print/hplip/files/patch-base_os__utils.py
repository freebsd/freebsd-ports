--- base/os_utils.py.orig	2022-02-23 07:41:04 UTC
+++ base/os_utils.py
@@ -53,7 +53,7 @@ def getHPLIPDir():
     status = 0
     if not os.path.exists(hplipdir):
         try:
-            os.umask(0)
+            os.umask(0o022)
             s = os.stat(homedir)
             os.mkdir(hplipdir, 0o755)
             os.chown(hplipdir, s[stat.ST_UID], s[stat.ST_GID])
