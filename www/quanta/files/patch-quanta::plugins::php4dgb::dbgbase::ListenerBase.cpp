--- quanta/plugins/php4dbg/dbgbase/ListenerBase.cpp.orig	Thu Jan 24 17:09:23 2002
+++ quanta/plugins/php4dbg/dbgbase/ListenerBase.cpp	Thu Jan 24 17:09:52 2002
@@ -11,11 +11,13 @@
                            the world-wide-web at http://dd.cron.ru/license
  ***************************************************************************/
 
+#include <sys/types.h>
+#include <stdio.h>
+#include <assert.h>
 #include "dbg_core.h"
 #include "ListenerBase.h"
 #include "ThreadBase.h"
-#include <stdio.h>
-#include <assert.h>
+
 
 ListenerBase::~ListenerBase() {
 	DBGTRACE("ListenerBase::~ListenerBase\n");
