--- src/classes/exceptions.py.orig	2021-08-24 18:04:45 UTC
+++ src/classes/exceptions.py
@@ -109,6 +109,8 @@ def libopenshot_crash_recovery():
         # Format last log line based on OS (since each OS can be formatted differently)
         if platform.system() == "Darwin":
             last_log_line = "mac-%s" % last_log_line[58:].strip()
+        elif platform.system() == "FreeBSD":
+            last_log_line = "freebsd-%s" % last_log_line.replace("/usr/local/lib/", "")
         elif platform.system() == "Windows":
             last_log_line = "windows-%s" % last_log_line
         elif platform.system() == "Linux":
