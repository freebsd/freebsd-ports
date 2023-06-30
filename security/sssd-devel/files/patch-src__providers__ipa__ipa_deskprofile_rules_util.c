--- src/providers/ipa/ipa_deskprofile_rules_util.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ipa/ipa_deskprofile_rules_util.c
@@ -20,6 +20,8 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/types.h>
+#include <signal.h>
 #include "providers/ipa/ipa_deskprofile_rules_util.h"
 #include "providers/ipa/ipa_deskprofile_private.h"
 #include "providers/ipa/ipa_rules_common.h"
