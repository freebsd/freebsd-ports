--- ktools-1.1/include/konst.ui.dlg.h.orig	Thu Sep  6 10:51:48 2001
+++ ktools-1.1/include/konst.ui.dlg.h	Thu Sep  6 10:53:05 2001
@@ -4,6 +4,10 @@
 #include <list>
 #include <algorithm>
 
+#include <time.h>
+#include <unistd.h>
+#include <sys/types.h>
+
 #include "konst.conf.h"
 #include "konst.ui.window.h"
 #include "konst.ui.menu.h"
