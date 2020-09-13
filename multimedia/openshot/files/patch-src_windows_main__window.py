--- src/windows/main_window.py.orig	2020-09-11 19:59:04 UTC
+++ src/windows/main_window.py
@@ -256,6 +256,8 @@ class MainWindow(QMainWindow, updates.UpdateWatcher):
                 # Format last log line based on OS (since each OS can be formatted differently)
                 if platform.system() == "Darwin":
                     last_log_line = "mac-%s" % last_log_line[58:].strip()
+                elif platform.system() == "FreeBSD":
+                    last_log_line = "freebsd-%s" % last_log_line.replace("/usr/local/lib/", "")
                 elif platform.system() == "Windows":
                     last_log_line = "windows-%s" % last_log_line
                 elif platform.system() == "Linux":
