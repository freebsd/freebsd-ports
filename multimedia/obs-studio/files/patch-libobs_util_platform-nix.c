--- libobs/util/platform-nix.c.orig	2017-10-29 09:19:47 UTC
+++ libobs/util/platform-nix.c
@@ -38,6 +38,7 @@
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/user.h>
+#include <sys/sysctl.h>
 #include <unistd.h>
 #include <libprocstat.h>
 #else
