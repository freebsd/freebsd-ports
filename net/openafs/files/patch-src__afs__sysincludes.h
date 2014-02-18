diff --git a/src/afs/sysincludes.h b/src/afs/sysincludes.h
index 3e3a172..10343b8 100644
--- a/src/afs/sysincludes.h
+++ b/src/afs/sysincludes.h
@@ -202,6 +202,12 @@ typedef unsigned short etap_event_t;
 # include "h/systm.h"
 # include "h/time.h"
 
+# ifdef AFS_FBSD_ENV
+#  include <sys/socket.h>
+#  include <net/if.h>
+#  include <net/if_var.h>
+# endif
+
 # ifdef	AFS_AIX_ENV
 #  ifdef AFS_AIX41_ENV
 #   include "sys/statfs.h"
