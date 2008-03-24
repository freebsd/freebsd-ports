--- lib/memmem.c.orig	2008-02-07 07:24:38.000000000 -0500
+++ lib/memmem.c	2008-02-24 15:13:50.000000000 -0500
@@ -31,8 +31,10 @@
  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  * SUCH DAMAGE.
  */
-#ifndef __sun
+#if !defined(__sun) && !defined(__FreeBSD__)
 #include "bbs.h"
+#endif
+#ifndef __sun
 #include <sys/cdefs.h>
 #endif
 
