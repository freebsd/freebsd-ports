--- quanta/plugins/php4dbg/dbgbase/dbg_core.c.orig	Thu Jan 24 16:53:35 2002
+++ quanta/plugins/php4dbg/dbgbase/dbg_core.c	Thu Jan 24 16:53:42 2002
@@ -11,9 +11,9 @@
                            the world-wide-web at http://dd.cron.ru/license
  ***************************************************************************/
 
+#include <sys/types.h>
 #include "dbg_core.h"
 #include <string.h>
-#include <malloc.h>
 #include <stdlib.h>
 
 #ifdef DBG_USE_STDALLOCA
