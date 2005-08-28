--- lib/str.c.orig	Sun Aug 28 13:10:19 2005
+++ lib/str.c	Sun Aug 28 13:10:29 2005
@@ -14,6 +14,7 @@
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
+#include <sys/types.h>
 #include <stdio.h>
 #include <string.h>
 #include <sys/mman.h>
