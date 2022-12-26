--- src/classes/metrics.py.orig	2022-12-08 21:31:12 UTC
+++ src/classes/metrics.py
@@ -61,6 +61,11 @@ try:
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
