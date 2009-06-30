Index: bgpctl/irrfilter.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/irrfilter.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpctl/irrfilter.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/irrfilter.c	30 Jun 2009 06:40:06 -0000	1.2
@@ -15,6 +15,9 @@
  * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
 
 #include <sys/types.h>
 #include <sys/param.h>
