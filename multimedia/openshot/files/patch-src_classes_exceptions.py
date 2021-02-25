--- src/classes/exceptions.py.orig	2021-01-30 23:50:27 UTC
+++ src/classes/exceptions.py
@@ -120,6 +120,8 @@ def libopenshot_crash_recovery():
         # Format last log line based on OS (since each OS can be formatted differently)
         if platform.system() == "Darwin":
             last_log_line = "mac-%s" % last_log_line[58:].strip()
+        elif platform.system() == "FreeBSD":
+            last_log_line = "freebsd-%s" % last_log_line.replace("/usr/local/lib/", "")
         elif platform.system() == "Windows":
             last_log_line = "windows-%s" % last_log_line
         elif platform.system() == "Linux":
