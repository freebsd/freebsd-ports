--- src/monitor.d.orig	2019-04-24 07:47:09 UTC
+++ src/monitor.d
@@ -1,4 +1,5 @@
-import core.sys.linux.sys.inotify;
+// import core.sys.linux.sys.inotify;
+import freebsd_inotify;
 import core.stdc.errno;
 import core.sys.posix.poll, core.sys.posix.unistd;
 import std.exception, std.file, std.path, std.regex, std.stdio, std.string;
