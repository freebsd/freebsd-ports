--- util/ipa_krb5.c.orig	2026-07-01 19:22:03 UTC
+++ util/ipa_krb5.c
@@ -20,7 +20,11 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
 #include <string.h>
+#include <strings.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <lber.h>
