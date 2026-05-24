net/aquantia-atlantic-kmod fixes for aq_hw.c:

1) Drop <unistd.h>, a userland header that breaks the kernel build.
   Aquantia PR: https://github.com/Aquantia/aqtion-freebsd/pull/27

2) aq_hw_rss_set()'s bitary[] is one u16 too short, so the indirection-table
   pack loop's last 32-bit write (i==63) lands one element past the array --
   an out-of-bounds stack write. Depending on stack layout it either trips
   -fstack-protector (kernel panic on ifconfig up) or returns and leaves the
   driver unable to bring up link. Sizing it [1 + (...*3/16)] fixes both.

--- aq_hw.c.orig
+++ aq_hw.c
@@ -32,7 +32,6 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <unistd.h>
 #include <sys/endian.h>
 #include <sys/param.h>
 #include <sys/systm.h>
@@ -854,7 +853,7 @@
 
 int aq_hw_rss_set(struct aq_hw_s *self, u8 rss_table[HW_ATL_RSS_INDIRECTION_TABLE_MAX])
 {
-	u16 bitary[(HW_ATL_RSS_INDIRECTION_TABLE_MAX *
+	u16 bitary[1 + (HW_ATL_RSS_INDIRECTION_TABLE_MAX *
 					3 / 16U)];
 	int err = 0;
 	u32 i = 0U;
