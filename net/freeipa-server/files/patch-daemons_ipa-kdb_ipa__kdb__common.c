--- daemons/ipa-kdb/ipa_kdb_common.c.orig	2026-07-01 19:44:19 UTC
+++ daemons/ipa-kdb/ipa_kdb_common.c
@@ -20,6 +20,10 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#ifdef __FreeBSD__
+#define _XOPEN_SOURCE 700
+#endif
+
 #include "ipa_kdb.h"
 #include <unicase.h>
 
