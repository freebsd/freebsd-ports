--- if_re.c.orig	2024-06-04 09:39:04 UTC
+++ if_re.c
@@ -67,6 +67,7 @@ __FBSDID("$FreeBSD: src/sys/dev/re/if_re.c,v " RE_VERS
 
 #include <net/if.h>
 #include <net/if_var.h>
+#include <net/if_private.h>
 #include <net/if_arp.h>
 #include <net/ethernet.h>
 #include <net/if_dl.h>
