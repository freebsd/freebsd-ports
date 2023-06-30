--- src/lib/winbind_idmap_sss/winbind_idmap_sss.c.orig	2023-05-05 08:11:07 UTC
+++ src/lib/winbind_idmap_sss/winbind_idmap_sss.c
@@ -22,6 +22,8 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <string.h>
 #include <errno.h>
 
