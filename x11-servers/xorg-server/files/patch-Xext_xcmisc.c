diff --git Xext/xcmisc.c Xext/xcmisc.c
index f26218e..8c7a86e 100644
--- Xext/xcmisc.c
+++ Xext/xcmisc.c
@@ -42,6 +42,12 @@ #include "swaprep.h"
 #include <X11/extensions/xcmiscstr.h>
 #include "modinit.h"
 
+#if HAVE_STDINT_H
+#include <stdint.h>
+#elif !defined(UINT32_MAX)
+#define UINT32_MAX 0xffffffffU
+#endif
+
 #if 0
 static unsigned char XCMiscCode;
 #endif
@@ -143,7 +149,10 @@ ProcXCMiscGetXIDList(client)
 
     REQUEST_SIZE_MATCH(xXCMiscGetXIDListReq);
 
-    pids = (XID *)ALLOCATE_LOCAL(stuff->count * sizeof(XID));
+    if (stuff->count > UINT32_MAX / sizeof(XID))
+	    return BadAlloc;
+
+    pids = (XID *)Xalloc(stuff->count * sizeof(XID));
     if (!pids)
     {
 	return BadAlloc;
@@ -164,7 +173,7 @@ ProcXCMiscGetXIDList(client)
     	client->pSwapReplyFunc = (ReplySwapPtr) Swap32Write;
 	WriteSwappedDataToClient(client, count * sizeof(XID), pids);
     }
-    DEALLOCATE_LOCAL(pids);
+    Xfree(pids);
     return(client->noClientException);
 }
 
