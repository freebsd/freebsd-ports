--- /usr/ports/sysutils/koncd/files/patch-koncd::mastercd_gui.h	Thu Jan  1 09:00:00 1970
+++ koncd/files/patch-koncd::mastercd_gui.h	Wed Dec 26 21:49:38 2001
@@ -0,0 +1,10 @@
+--- koncd/mastercd_gui.h.orig	Sat Oct 13 01:40:01 2001
++++ koncd/mastercd_gui.h	Wed Dec 26 21:48:38 2001
+@@ -11,6 +11,7 @@
+ 
+ #include <qvariant.h>
+ #include <qdialog.h>
++#include <klistview.h>
+ class QVBoxLayout; 
+ class QHBoxLayout; 
+ class QGridLayout; 
