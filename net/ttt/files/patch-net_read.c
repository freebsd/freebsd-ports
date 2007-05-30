
	Included patch fixes the problem

--- patch-net_read.c begins here ---
--- net_read.c.orig	Tue May 29 11:16:23 2007
+++ net_read.c	Tue May 29 11:16:48 2007
@@ -58,6 +58,7 @@
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
+#include <net/bpf.h>
 #ifdef __OpenBSD__
 #include <net/if_pflog.h>
 #endif
--- patch-net_read.c ends here ---


