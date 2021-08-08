--- src/read_blocks.c.orig	2021-08-01 16:18:33 UTC
+++ src/read_blocks.c
@@ -13,6 +13,7 @@
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
+#define _POSIX_C_SOURCE 200809L
 #include "unicode_blocks.h"
 #include <stdio.h>
 #include <stdlib.h>
