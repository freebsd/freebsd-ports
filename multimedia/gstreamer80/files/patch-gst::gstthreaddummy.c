--- gst/gstthreaddummy.c.orig	Sat Aug 30 19:30:10 2003
+++ gst/gstthreaddummy.c	Sat Aug 30 19:30:34 2003
@@ -17,7 +17,9 @@
  * Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <sys/time.h>
+#include <unistd.h>
 #include <glib.h>
 #include "gstlog.h"
 
