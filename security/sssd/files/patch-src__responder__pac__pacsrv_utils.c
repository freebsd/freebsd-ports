From 93a41acb0f1434d1638cc796c4529a135d61409d Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 30 Oct 2013 10:49:27 +0100
Subject: [PATCH 4/4] patch-src__responder__pac__pacsrv_utils.c

---
 src/responder/pac/pacsrv_utils.c | 1 +
 1 file changed, 1 insertion(+)

diff --git src/responder/pac/pacsrv_utils.c src/responder/pac/pacsrv_utils.c
index 3ac7b84..6052432 100644
--- src/responder/pac/pacsrv_utils.c
+++ src/responder/pac/pacsrv_utils.c
@@ -18,6 +18,7 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
+#include <sys/types.h>
 #include <stdbool.h>
 #include <util/data_blob.h>
 #include <gen_ndr/security.h>
-- 
1.8.0
