--- src/providers/ad/ad_pac_common.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ad/ad_pac_common.c
@@ -20,6 +20,8 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/types.h>
+#include <sys/time.h>
 
 #include "providers/ad/ad_pac.h"
 #include "util/util.h"
