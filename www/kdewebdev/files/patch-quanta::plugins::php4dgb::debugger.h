--- quanta/plugins/php4dbg/debugger.h.orig	Thu Jan 24 17:22:31 2002
+++ quanta/plugins/php4dbg/debugger.h	Thu Jan 24 17:22:47 2002
@@ -6,6 +6,7 @@
 #endif
 
 #include <qobject.h>
+#include <sys/types.h>
 
 class Listener;
 class QSocketNotifier;
