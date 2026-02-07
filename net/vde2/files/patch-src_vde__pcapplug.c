--- src/vde_pcapplug.c.orig	2011-11-23 16:41:18 UTC
+++ src/vde_pcapplug.c
@@ -24,6 +24,7 @@
 #include <errno.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#include <net/bpf.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
