--- ./libfprint/drivers/vfs301_proto.h.ORIG	2013-06-26 14:13:00.000000000 +0200
+++ ./libfprint/drivers/vfs301_proto.h	2014-04-21 11:09:27.000000000 +0200
@@ -18,7 +18,7 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
-#include <libusb-1.0/libusb.h>
+#include <libusb.h>
 
 enum {
 	VFS301_DEFAULT_WAIT_TIMEOUT = 300,
