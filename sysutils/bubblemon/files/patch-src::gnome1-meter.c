--- src/gnome1-meter.c.orig	Thu Dec 26 00:39:39 2002
+++ src/gnome1-meter.c	Thu Dec 26 00:39:54 2002
@@ -20,6 +20,7 @@
  *  Foundation, Inc., 59 Temple Street #330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <glibtop.h>
 #include <glibtop/cpu.h>
 #include <glibtop/mem.h>
