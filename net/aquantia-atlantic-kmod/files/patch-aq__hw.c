net/aquantia-atlantic-kmod fixes for aq_hw.c:

1) Drop <unistd.h>, a userland header that breaks the kernel build.
   Upstream PR: https://github.com/Aquantia/aqtion-freebsd/pull/27

2) aq_hw_rss_set()'s bitary[] is one u16 too short; the indirection-table
   pack loop writes one element past it, smashing the stack canary (panic on
   "ifconfig up") and corrupting the link-speed request (interface attaches
   but stays "no carrier").  Size it [1 + (...*3/16)].

--- aq_hw.c.orig
+++ aq_hw.c
@@ -32,7 +32,6 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <unistd.h>
 #include <sys/endian.h>
 #include <sys/param.h>
 #include <sys/systm.h>
@@ -854,7 +853,13 @@
 
 int aq_hw_rss_set(struct aq_hw_s *self, u8 rss_table[HW_ATL_RSS_INDIRECTION_TABLE_MAX])
 {
-	u16 bitary[(HW_ATL_RSS_INDIRECTION_TABLE_MAX *
+	/*
+	 * aq_hw_rss_set()'s bitary[] is one u16 too short; the indirection-table
+	 * pack loop writes one element past it, smashing the stack canary (panic
+	 * on "ifconfig up") and corrupting the link-speed request (interface
+	 * attaches but stays "no carrier").  Size it [1 + (...*3/16)].
+	 */
+	u16 bitary[1 + (HW_ATL_RSS_INDIRECTION_TABLE_MAX *
 					3 / 16U)];
 	int err = 0;
 	u32 i = 0U;
