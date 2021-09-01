--- src/classes/metrics.py.orig	2021-08-24 18:04:45 UTC
+++ src/classes/metrics.py
@@ -60,6 +60,11 @@ try:
         os_version = "Macintosh; Intel Mac OS X %s" % v[0].replace(".", "_")
         os_distro = "OS X %s" % v[0]
 
+    elif 1 and platform.system() == "FreeBSD":
+        v = platform.version().split(" ")
+        os_version = "X11; %s %s" % (v[0], platform.machine())
+        os_distro = " ".join([v[0], v[1]])
+
     elif platform.system() == "Windows":
         v = platform.win32_ver()
         os_version = "Windows NT %s; %s" % (v[0], v[1])
