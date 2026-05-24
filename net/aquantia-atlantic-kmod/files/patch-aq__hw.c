net/aquantia-atlantic-kmod fixes for aq_hw.c:

1) Drop <unistd.h>, a userland header that breaks the kernel build.
   Aquantia PR: https://github.com/Aquantia/aqtion-freebsd/pull/27

2) Fix an out-of-bounds stack write in aq_hw_rss_set().  RSS table entries
   are 3 bits (8 queues max), but with more than 8 RX rings rss_table[]
   holds larger values; the 32-bit write then spills one u16 past bitary[]
   and corrupts the stack, so the NIC never links or the kernel panics.
   Mask each value to 3 bits and pack 16 bits at a time to keep the write
   in bounds.

--- aq_hw.c.orig
+++ aq_hw.c
@@ -32,7 +32,6 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <unistd.h>
 #include <sys/endian.h>
 #include <sys/param.h>
 #include <sys/systm.h>
@@ -862,8 +861,14 @@
 	memset(bitary, 0, sizeof(bitary));
 
 	for (i = HW_ATL_RSS_INDIRECTION_TABLE_MAX; i--;) {
-		(*(u32 *)(bitary + ((i * 3U) / 16U))) |=
-			((rss_table[i]) << ((i * 3U) & 0xFU));
+		u32 bit_pos = i * 3U;
+		u32 word = bit_pos / 16U;
+		u32 shift = bit_pos % 16U;
+		u32 val = (u32)(rss_table[i] & 0x7U) << shift;
+
+		bitary[word] |= (u16)val;
+		if ((val >> 16) && word + 1U < ARRAY_SIZE(bitary))
+			bitary[word + 1U] |= (u16)(val >> 16);
 	}
 
 	for (i = ARRAY_SIZE(bitary); i--;) {
