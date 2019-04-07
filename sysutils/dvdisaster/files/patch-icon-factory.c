--- icon-factory.c.orig	2019-03-06 11:28:20 UTC
+++ icon-factory.c
@@ -20,6 +20,8 @@
  *  along with dvdisaster. If not, see <http://www.gnu.org/licenses/>.
  */
 
+#define GDK_PIXBUF_VERSION_MIN_REQUIRED GDK_PIXBUF_VERSION_2_30
+
 #include "dvdisaster.h"
 
 #include "inlined-icons.h"
