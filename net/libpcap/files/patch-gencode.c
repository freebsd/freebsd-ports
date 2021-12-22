--- gencode.c.orig	2021-06-07 20:21:35 UTC
+++ gencode.c
@@ -59,10 +59,16 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/pfvar.h>
-#include <net/if_pflog.h>
 #endif /* HAVE_NET_PFVAR_H */
 
 #include "pcap-int.h"
+
+#ifdef HAVE_NET_PFVAR_H
+/* FreeBSD includes <net/bpf.h> from <net/if_pflog.h>, and indirectly includes
+ * <net/dlt.h>. The FreeBSD version lacks DLT_IEEE802_15_4_TAP, so we really
+ * want to use our own version. */
+#include <net/if_pflog.h>
+#endif /* HAVE_NET_PFVAR_H */
 
 #include "extract.h"
 
