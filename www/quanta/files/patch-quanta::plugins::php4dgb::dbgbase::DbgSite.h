--- quanta/plugins/php4dbg/dbgbase/DbgSite.h.orig	Thu Jan 24 17:01:33 2002
+++ quanta/plugins/php4dbg/dbgbase/DbgSite.h	Thu Jan 24 17:01:48 2002
@@ -14,6 +14,7 @@
 #ifndef _DBGSITE_H_
 #define _DBGSITE_H_
 
+#include <sys/types.h>
 #include <qobject.h>
 #include "ListenerGlobals.h"
 #include "RequestorBase.h"
