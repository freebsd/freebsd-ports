--- quanta/plugins/php4dbg/dbgbase/ThreadBase.cpp.orig	Thu Jan 24 16:52:35 2002
+++ quanta/plugins/php4dbg/dbgbase/ThreadBase.cpp	Thu Jan 24 16:52:44 2002
@@ -11,6 +11,7 @@
                            the world-wide-web at http://dd.cron.ru/license
  ***************************************************************************/
 
+#include <sys/types.h>
 #include "ThreadBase.h"
 #include "ListenerGlobals.h"
 #include "dbg_core.h"
