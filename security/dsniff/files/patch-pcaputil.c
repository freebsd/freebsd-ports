--- pcaputil.c.orig	2001-03-15 08:33:04 UTC
+++ pcaputil.c
@@ -17,20 +17,9 @@
 #include <string.h>
 #include <err.h>
 #include <pcap.h>
-#ifdef BSD
-#include <pcap-int.h>
-#endif
 
 #include "pcaputil.h"
 
-#ifdef BSD
-static int
-bpf_immediate(int fd, int on)
-{
-	return (ioctl(fd, BIOCIMMEDIATE, &on));
-}
-#endif
-
 int
 pcap_dloff(pcap_t *pd)
 {
@@ -87,12 +76,6 @@ pcap_init(char *intf, char *filter, int 
 		pcap_perror(pd, "pcap_compile");
 		return (NULL);
 	}
-#ifdef BSD
-	if (bpf_immediate(pd->fd, 1) < 0) {
-		perror("ioctl");
-		return (NULL);
-	}
-#endif
 	return (pd);
 }
 
