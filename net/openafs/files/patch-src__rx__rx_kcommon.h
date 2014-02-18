diff --git a/src/rx/rx_kcommon.h b/src/rx/rx_kcommon.h
index 9b04123..92752db 100644
--- a/src/rx/rx_kcommon.h
+++ b/src/rx/rx_kcommon.h
@@ -124,6 +124,11 @@ typedef unsigned short etap_event_t;
 #include "h/file.h"
 #endif
 #include "net/if.h"
+# ifdef AFS_FBSD_ENV
+#  include <sys/socket.h>
+#  include <net/if.h>
+#  include <net/if_var.h>
+# endif
 #endif
 #if !defined(AFS_HPUX110_ENV) && !defined(AFS_LINUX22_ENV) && !defined(AFS_DARWIN_ENV)
 #include "netinet/in_var.h"
