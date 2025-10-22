--- python/samba/tdb_util.py.orig	2025-02-17 11:38:24.136379000 +0100
+++ python/samba/tdb_util.py	2025-02-17 11:38:44.171612000 +0100
@@ -37,9 +37,10 @@
         raise FileNotFoundError(2, "could not find tdbbackup tool: "
                                 "is tdb-tools installed?")

-    tdbbackup_cmd = [toolpath, "-s", ".copy.tdb", file1]
     if readonly:
-        tdbbackup_cmd.append("-r")
+        tdbbackup_cmd = [toolpath, "-r", "-s", ".copy.tdb", file1]
+    else:
+        tdbbackup_cmd = [toolpath, "-s", ".copy.tdb", file1]

     status = subprocess.check_call(tdbbackup_cmd, close_fds=True, shell=False)

