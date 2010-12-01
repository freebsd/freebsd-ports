--- src/uzbl-core.c.orig	2010-11-29 20:00:45.000000000 +0100
+++ src/uzbl-core.c	2010-11-29 19:59:16.000000000 +0100
@@ -29,6 +29,7 @@
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#include <sys/errno.h>
 #include "uzbl-core.h"
 #include "callbacks.h"
 #include "events.h"
