--- src/gnome1-meter.c.orig	Tue Jul  8 02:09:17 2003
+++ src/gnome1-meter.c	Tue Jul  8 02:09:25 2003
@@ -20,6 +20,7 @@
  *  Foundation, Inc., 59 Temple Street #330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <glibtop.h>
 #include <glibtop/cpu.h>
 #include <glibtop/mem.h>
