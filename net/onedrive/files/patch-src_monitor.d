--- src/monitor.d.orig	2024-09-18 07:16:29 UTC
+++ src/monitor.d
@@ -4,7 +4,8 @@ import core.stdc.stdlib;
 // What does this module require to function?
 import core.stdc.errno;
 import core.stdc.stdlib;
-import core.sys.linux.sys.inotify;
+// import core.sys.linux.sys.inotify;
+import freebsd_inotify;
 import core.sys.posix.poll;
 import core.sys.posix.unistd;
 import core.sys.posix.sys.select;
