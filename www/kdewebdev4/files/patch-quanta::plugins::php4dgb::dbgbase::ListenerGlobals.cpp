--- quanta/plugins/php4dbg/dbgbase/ListenerGlobals.cpp.orig	Thu Jan 24 16:50:10 2002
+++ quanta/plugins/php4dbg/dbgbase/ListenerGlobals.cpp	Thu Jan 24 16:51:58 2002
@@ -11,6 +11,7 @@
                            the world-wide-web at http://dd.cron.ru/license
  ***************************************************************************/
 
+#include <sys/types.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include "ListenerGlobals.h"
@@ -344,7 +345,7 @@
 	ret_val = select(listen_socket + 1, &rset, NULL, NULL, &timeout);
 	if (ret_val>0) {
 		siz = sizeof(laddr);
-		ret_val = accept(listen_socket, &laddr, &siz);
+	       ret_val = accept(listen_socket, &laddr,(socklen_t *) &siz);
 	}
 	if (ret_val <= 0) {
 		return (ret_val) ? (-1) : (0);
