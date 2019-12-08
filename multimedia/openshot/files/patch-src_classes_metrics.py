--- src/classes/metrics.py.orig	2019-11-11 07:57:57 UTC
+++ src/classes/metrics.py
@@ -53,6 +53,11 @@ try:
         os_version = "Macintosh; Intel Mac OS X %s" % v[0].replace(".", "_")
         linux_distro = "OS X %s" % v[0]
 
+    elif 0 and platform.system() == "FreeBSD":
+        v = platform.version().split(" ")
+        os_version = "X11; %s %s" % (v[0], platform.machine())
+        linux_distro = " ".join([v[0], v[1]])
+
     elif platform.system() == "Windows":
         v = platform.win32_ver()
         # TODO: Upgrade windows python (on build server) version to 3.5, so it correctly identifies Windows 10
