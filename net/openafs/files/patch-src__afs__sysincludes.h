diff --git a/src/afs/sysincludes.h b/src/afs/sysincludes.h
index 5840227..9d68b1e 100644
--- a/src/afs/sysincludes.h
+++ b/src/afs/sysincludes.h
@@ -288,7 +288,7 @@ typedef unsigned short etap_event_t;
 # include "h/protosw.h"
 
 # if defined(AFS_FBSD_ENV)
-#  include "limits.h"
+#  include "sys/limits.h"
 # endif
 
 # ifdef AFS_HPUX_ENV
