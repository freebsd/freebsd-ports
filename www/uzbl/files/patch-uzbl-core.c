--- src/uzbl-core.c.orig	2016-02-28 14:27:33 UTC
+++ src/uzbl-core.c
@@ -27,6 +27,7 @@
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#include <sys/errno.h>
 #include "uzbl-core.h"
 
 #include "commands.h"
