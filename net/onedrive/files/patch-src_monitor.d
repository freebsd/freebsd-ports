--- src/monitor.d.orig	2019-03-16 11:55:35 UTC
+++ src/monitor.d
@@ -1,10 +1,11 @@
-import core.sys.linux.sys.inotify;
+// import core.sys.linux.sys.inotify;
 import core.stdc.errno;
 import core.sys.posix.poll, core.sys.posix.unistd;
 import std.exception, std.file, std.path, std.regex, std.stdio, std.string;
 import config;
 import selective;
 import util;
+import freebsd_inotify;
 static import log;
 
 // relevant inotify events
