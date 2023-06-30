--- src/util/sss_krb5.c.orig	2023-05-05 08:11:07 UTC
+++ src/util/sss_krb5.c
@@ -17,6 +17,8 @@
     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
+#include <sys/types.h>
+#include <sys/endian.h>
 #include <ctype.h>
 #include <stdio.h>
 #include <errno.h>
