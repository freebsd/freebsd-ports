--- lib/libalpm/util.c.orig	2017-05-18 11:10:47 UTC
+++ lib/libalpm/util.c
@@ -32,6 +32,7 @@
 #include <sys/wait.h>
 #include <fnmatch.h>
 #include <poll.h>
+#include <signal.h>
 
 /* libarchive */
 #include <archive.h>
