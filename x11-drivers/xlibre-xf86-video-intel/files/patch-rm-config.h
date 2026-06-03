--- benchmarks/dri2-swap.c.orig	2025-12-24 12:33:59.517092000 +0000
+++ benchmarks/dri2-swap.c	2025-12-24 12:34:23.006732000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
--- benchmarks/dri3-swap.c.orig	2025-12-24 12:33:59.517739000 +0000
+++ benchmarks/dri3-swap.c	2025-12-24 12:34:23.006896000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
--- src/backlight.c.orig	2025-12-24 12:33:59.035493000 +0000
+++ src/backlight.c	2025-12-24 12:34:22.984891000 +0000
@@ -24,7 +24,7 @@
  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
  **************************************************************************/
-#include "config.h"
+
 
 #include <sys/types.h>
 #include <sys/wait.h>
--- src/fd.c.orig	2025-12-24 12:33:59.196171000 +0000
+++ src/fd.c	2025-12-24 12:34:22.989406000 +0000
@@ -23,7 +23,7 @@
  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
  **************************************************************************/
-#include "config.h"
+
 
 #include <xorg-server.h>
 
--- src/intel_device.c.orig	2025-12-24 12:33:57.763987000 +0000
+++ src/intel_device.c	2025-12-24 12:34:22.960702000 +0000
@@ -23,7 +23,7 @@
  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
  **************************************************************************/
-#include "config.h"
+
 
 #include <sys/types.h>
 #include <sys/stat.h>
--- src/intel_module.c.orig	2025-12-24 12:33:58.953364000 +0000
+++ src/intel_module.c	2025-12-24 12:34:22.982857000 +0000
@@ -23,7 +23,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <xorg-server.h>
 #include <xorgVersion.h>
--- src/intel_options.c.orig	2025-12-24 12:33:57.730213000 +0000
+++ src/intel_options.c	2025-12-24 12:34:22.960465000 +0000
@@ -1,4 +1,4 @@
-#include "config.h"
+
 
 #include <xorg-server.h>
 #include <xorgVersion.h>
--- src/legacy/i810/i810_accel.c.orig	2025-12-24 12:33:59.008249000 +0000
+++ src/legacy/i810/i810_accel.c	2025-12-24 12:34:22.984244000 +0000
@@ -25,7 +25,7 @@
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 **************************************************************************/
-#include "config.h"
+
 
 /*
  * Authors:
--- src/legacy/i810/i810_cursor.c.orig	2025-12-24 12:33:58.980951000 +0000
+++ src/legacy/i810/i810_cursor.c	2025-12-24 12:34:22.983133000 +0000
@@ -25,7 +25,7 @@
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 **************************************************************************/
-#include "config.h"
+
 
 /*
  * Authors:
--- src/legacy/i810/i810_dga.c.orig	2025-12-24 12:33:59.017887000 +0000
+++ src/legacy/i810/i810_dga.c	2025-12-24 12:34:22.984360000 +0000
@@ -21,7 +21,7 @@
  *
  * Authors:  Alan Hourihane, <alanh@fairlite.demon.co.uk>
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/legacy/i810/i810_dri.c.orig	2025-12-24 12:33:59.007973000 +0000
+++ src/legacy/i810/i810_dri.c	2025-12-24 12:34:22.984089000 +0000
@@ -1,4 +1,4 @@
-#include "config.h"
+
 
 #include <errno.h>
 #include <stdio.h>
--- src/legacy/i810/i810_driver.c.orig	2025-12-24 12:33:59.018288000 +0000
+++ src/legacy/i810/i810_driver.c	2025-12-24 12:34:22.984723000 +0000
@@ -25,7 +25,7 @@
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 **************************************************************************/
-#include "config.h"
+
 
 /*
  * Authors:
--- src/legacy/i810/i810_hwmc.c.orig	2025-12-24 12:33:58.990104000 +0000
+++ src/legacy/i810/i810_hwmc.c	2025-12-24 12:34:22.983287000 +0000
@@ -32,7 +32,7 @@
  *
  *
  */
-#include "config.h"
+
 
 #include <string.h>
 
--- src/legacy/i810/i810_memory.c.orig	2025-12-24 12:33:58.990314000 +0000
+++ src/legacy/i810/i810_memory.c	2025-12-24 12:34:22.983449000 +0000
@@ -24,7 +24,7 @@
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 **************************************************************************/
-#include "config.h"
+
 
 /*
  * Authors:
--- src/legacy/i810/i810_video.c.orig	2025-12-24 12:33:59.007317000 +0000
+++ src/legacy/i810/i810_video.c	2025-12-24 12:34:22.983743000 +0000
@@ -32,7 +32,7 @@
  *      Offscreen Images:
  *        Matt Sottek <matthew.j.sottek@intel.com>
  */
-#include "config.h"
+
 
 #include <string.h>
 
--- src/legacy/i810/i810_wmark.c.orig	2025-12-24 12:33:58.964828000 +0000
+++ src/legacy/i810/i810_wmark.c	2025-12-24 12:34:22.983003000 +0000
@@ -29,7 +29,7 @@
  * Authors:
  *   Keith Whitwell <keith@tungstengraphics.com>
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/sna/blt.c.orig	2025-12-24 12:33:58.639357000 +0000
+++ src/sna/blt.c	2025-12-24 12:34:22.981974000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include <pixman.h>
--- src/sna/brw/brw_eu.c.orig	2025-12-24 12:33:57.815306000 +0000
+++ src/sna/brw/brw_eu.c	2025-12-24 12:34:22.961155000 +0000
@@ -28,7 +28,7 @@
   * Authors:
   *   Keith Whitwell <keith@tungstengraphics.com>
   */
-#include "config.h"
+
 
 #include "brw_eu.h"
 
--- src/sna/gen2_render.c.orig	2025-12-24 12:33:58.607869000 +0000
+++ src/sna/gen2_render.c	2025-12-24 12:34:22.980348000 +0000
@@ -26,7 +26,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/gen3_render.c.orig	2025-12-24 12:33:58.520598000 +0000
+++ src/sna/gen3_render.c	2025-12-24 12:34:22.977539000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/gen4_common.c.orig	2025-12-24 12:33:58.258443000 +0000
+++ src/sna/gen4_common.c	2025-12-24 12:34:22.967773000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "gen4_common.h"
 #include "gen4_vertex.h"
--- src/sna/gen4_render.c.orig	2025-12-24 12:33:58.595999000 +0000
+++ src/sna/gen4_render.c	2025-12-24 12:34:22.979729000 +0000
@@ -29,7 +29,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/gen4_source.c.orig	2025-12-24 12:33:58.542068000 +0000
+++ src/sna/gen4_source.c	2025-12-24 12:34:22.978644000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/gen4_vertex.c.orig	2025-12-24 12:33:58.197163000 +0000
+++ src/sna/gen4_vertex.c	2025-12-24 12:34:22.965975000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/gen5_render.c.orig	2025-12-24 12:33:58.625560000 +0000
+++ src/sna/gen5_render.c	2025-12-24 12:34:22.981612000 +0000
@@ -29,7 +29,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/gen6_common.c.orig	2025-12-24 12:33:58.521168000 +0000
+++ src/sna/gen6_common.c	2025-12-24 12:34:22.977894000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "gen6_common.h"
 #include "gen4_vertex.h"
--- src/sna/gen6_render.c.orig	2025-12-24 12:33:58.020086000 +0000
+++ src/sna/gen6_render.c	2025-12-24 12:34:22.963236000 +0000
@@ -29,7 +29,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/gen7_render.c.orig	2025-12-24 12:33:58.313961000 +0000
+++ src/sna/gen7_render.c	2025-12-24 12:34:22.968852000 +0000
@@ -29,7 +29,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/gen8_eu.c.orig	2025-12-24 12:33:58.595451000 +0000
+++ src/sna/gen8_eu.c	2025-12-24 12:34:22.979207000 +0000
@@ -20,7 +20,7 @@
  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  * IN THE SOFTWARE.
  */
-#include "config.h"
+
 
 #include <string.h>
 
--- src/sna/gen8_render.c.orig	2025-12-24 12:33:58.314568000 +0000
+++ src/sna/gen8_render.c	2025-12-24 12:34:22.969493000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/gen8_vertex.c.orig	2025-12-24 12:33:58.608577000 +0000
+++ src/sna/gen8_vertex.c	2025-12-24 12:34:22.980661000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/gen9_render.c.orig	2025-12-24 12:33:58.009918000 +0000
+++ src/sna/gen9_render.c	2025-12-24 12:34:22.962596000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/kgem.c.orig	2025-12-24 12:33:58.037666000 +0000
+++ src/sna/kgem.c	2025-12-24 12:34:22.965066000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/kgem_debug.c.orig	2025-12-24 12:33:58.446801000 +0000
+++ src/sna/kgem_debug.c	2025-12-24 12:34:22.973877000 +0000
@@ -24,7 +24,7 @@
  *    Eric Anholt <eric@anholt.net>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/kgem_debug_gen2.c.orig	2025-12-24 12:33:58.447102000 +0000
+++ src/sna/kgem_debug_gen2.c	2025-12-24 12:34:22.974049000 +0000
@@ -25,7 +25,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/kgem_debug_gen3.c.orig	2025-12-24 12:33:58.428183000 +0000
+++ src/sna/kgem_debug_gen3.c	2025-12-24 12:34:22.973701000 +0000
@@ -25,7 +25,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/kgem_debug_gen4.c.orig	2025-12-24 12:33:58.609053000 +0000
+++ src/sna/kgem_debug_gen4.c	2025-12-24 12:34:22.981016000 +0000
@@ -25,7 +25,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/kgem_debug_gen5.c.orig	2025-12-24 12:33:58.608829000 +0000
+++ src/sna/kgem_debug_gen5.c	2025-12-24 12:34:22.980839000 +0000
@@ -25,7 +25,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/kgem_debug_gen6.c.orig	2025-12-24 12:33:58.541896000 +0000
+++ src/sna/kgem_debug_gen6.c	2025-12-24 12:34:22.978528000 +0000
@@ -25,7 +25,7 @@
  *    Chris Wilson <chris"chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/kgem_debug_gen7.c.orig	2025-12-24 12:33:58.542267000 +0000
+++ src/sna/kgem_debug_gen7.c	2025-12-24 12:34:22.978824000 +0000
@@ -25,7 +25,7 @@
  *    Chris Wilson <chris"chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/mman.h>
 #include <assert.h>
--- src/sna/sna_accel.c.orig	2025-12-24 12:33:58.394314000 +0000
+++ src/sna/sna_accel.c	2025-12-24 12:34:22.972940000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_reg.h"
--- src/sna/sna_acpi.c.orig	2025-12-24 12:33:58.594869000 +0000
+++ src/sna/sna_acpi.c	2025-12-24 12:34:22.978942000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include <sys/types.h>
 #include <sys/socket.h>
--- src/sna/sna_blt.c.orig	2025-12-24 12:33:58.229805000 +0000
+++ src/sna/sna_blt.c	2025-12-24 12:34:22.967535000 +0000
@@ -27,7 +27,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_composite.c.orig	2025-12-24 12:33:58.297307000 +0000
+++ src/sna/sna_composite.c	2025-12-24 12:34:22.968237000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_cpu.c.orig	2025-12-24 12:33:58.519651000 +0000
+++ src/sna/sna_cpu.c	2025-12-24 12:34:22.976594000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_cpuid.h"
--- src/sna/sna_damage.c.orig	2025-12-24 12:33:57.997750000 +0000
+++ src/sna/sna_damage.c	2025-12-24 12:34:22.961920000 +0000
@@ -23,7 +23,7 @@
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
  **************************************************************************/
-#include "config.h"
+
 
 #include <xorg-server.h>
 #include <extinit.h>
--- src/sna/sna_display.c.orig	2025-12-24 12:33:58.449035000 +0000
+++ src/sna/sna_display.c	2025-12-24 12:34:22.975630000 +0000
@@ -25,7 +25,7 @@
  *    Dave Airlie <airlied@redhat.com>
  *
  */
-#include "config.h"
+
 
 #include <stdint.h>
 #include <sys/types.h>
--- src/sna/sna_display_fake.c.orig	2025-12-24 12:33:58.178286000 +0000
+++ src/sna/sna_display_fake.c	2025-12-24 12:34:22.965223000 +0000
@@ -24,7 +24,7 @@
  *	Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 
--- src/sna/sna_dri2.c.orig	2025-12-24 12:33:58.036346000 +0000
+++ src/sna/sna_dri2.c	2025-12-24 12:34:22.963842000 +0000
@@ -31,7 +31,7 @@
  *          David Dawes <dawes@xfree86.org>
  *          Keith Whitwell <keith@tungstengraphics.com>
  */
-#include "config.h"
+
 
 #include <errno.h>
 #include <time.h>
--- src/sna/sna_dri3.c.orig	2025-12-24 12:33:58.178640000 +0000
+++ src/sna/sna_dri3.c	2025-12-24 12:34:22.965413000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <sys/types.h>
 #include <fcntl.h>
--- src/sna/sna_driver.c.orig	2025-12-24 12:33:57.783069000 +0000
+++ src/sna/sna_driver.c	2025-12-24 12:34:22.961025000 +0000
@@ -32,7 +32,7 @@
  *          David Dawes <dawes@xfree86.org>
  *          Alan Hourihane <alanh@tungstengraphics.com>
  */
-#include "config.h"
+
 
 #include <string.h>
 #include <stdio.h>
--- src/sna/sna_glyphs.c.orig	2025-12-24 12:33:58.541542000 +0000
+++ src/sna/sna_glyphs.c	2025-12-24 12:34:22.978290000 +0000
@@ -57,7 +57,7 @@
  * Author: Chris Wilson <chris@chris-wilson.co.uk>
  * Based on code by: Keith Packard <keithp@keithp.com> and Owen Taylor <otaylor@fishsoup.net>
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_gradient.c.orig	2025-12-24 12:33:58.519453000 +0000
+++ src/sna/sna_gradient.c	2025-12-24 12:34:22.976490000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_io.c.orig	2025-12-24 12:33:58.639804000 +0000
+++ src/sna/sna_io.c	2025-12-24 12:34:22.982339000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_present.c.orig	2025-12-24 12:33:58.411137000 +0000
+++ src/sna/sna_present.c	2025-12-24 12:34:22.973202000 +0000
@@ -19,7 +19,7 @@
  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
  * OF THIS SOFTWARE.
  */
-#include "config.h"
+
 
 #include <sys/types.h>
 #include <fcntl.h>
--- src/sna/sna_render.c.orig	2025-12-24 12:33:57.976151000 +0000
+++ src/sna/sna_render.c	2025-12-24 12:34:22.961581000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_stream.c.orig	2025-12-24 12:33:58.216779000 +0000
+++ src/sna/sna_stream.c	2025-12-24 12:34:22.966824000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_threads.c.orig	2025-12-24 12:33:58.246372000 +0000
+++ src/sna/sna_threads.c	2025-12-24 12:34:22.967676000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 
--- src/sna/sna_tiling.c.orig	2025-12-24 12:33:58.449382000 +0000
+++ src/sna/sna_tiling.c	2025-12-24 12:34:22.975888000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_transform.c.orig	2025-12-24 12:33:58.449566000 +0000
+++ src/sna/sna_transform.c	2025-12-24 12:34:22.976018000 +0000
@@ -26,7 +26,7 @@
  *    Jesse Barns <jbarnes@virtuousgeek.org>
  *    Chris Wilson <chris@chris-wilson.co.uk>
  */
-#include "config.h"
+
 
 #include "sna.h"
 
--- src/sna/sna_trapezoids.c.orig	2025-12-24 12:33:58.520843000 +0000
+++ src/sna/sna_trapezoids.c	2025-12-24 12:34:22.977794000 +0000
@@ -26,7 +26,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_trapezoids_boxes.c.orig	2025-12-24 12:33:58.678873000 +0000
+++ src/sna/sna_trapezoids_boxes.c	2025-12-24 12:34:22.982639000 +0000
@@ -26,7 +26,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_trapezoids_imprecise.c.orig	2025-12-24 12:33:58.213367000 +0000
+++ src/sna/sna_trapezoids_imprecise.c	2025-12-24 12:34:22.966674000 +0000
@@ -26,7 +26,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_trapezoids_mono.c.orig	2025-12-24 12:33:58.328533000 +0000
+++ src/sna/sna_trapezoids_mono.c	2025-12-24 12:34:22.969799000 +0000
@@ -26,7 +26,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_trapezoids_precise.c.orig	2025-12-24 12:33:58.346443000 +0000
+++ src/sna/sna_trapezoids_precise.c	2025-12-24 12:34:22.970380000 +0000
@@ -26,7 +26,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_render.h"
--- src/sna/sna_vertex.c.orig	2025-12-24 12:33:58.472016000 +0000
+++ src/sna/sna_vertex.c	2025-12-24 12:34:22.976114000 +0000
@@ -24,7 +24,7 @@
  *    Chris Wilson <chris@chris-wilson.co.uk>
  *
  */
-#include "config.h"
+
 
 #include "sna.h"
 
--- src/sna/sna_video.c.orig	2025-12-24 12:33:58.519114000 +0000
+++ src/sna/sna_video.c	2025-12-24 12:34:22.976336000 +0000
@@ -40,7 +40,7 @@
  *      Offscreen Images:
  *        Matt Sottek <matthew.j.sottek@intel.com>
  */
-#include "config.h"
+
 
 #include <inttypes.h>
 #include <math.h>
--- src/sna/sna_video_hwmc.c.orig	2025-12-24 12:33:58.447443000 +0000
+++ src/sna/sna_video_hwmc.c	2025-12-24 12:34:22.974182000 +0000
@@ -24,7 +24,7 @@
  *    Zhenyu Wang <zhenyu.z.wang@sna.com>
  *
  */
-#include "config.h"
+
 
 #define _SNA_XVMC_SERVER_
 #include "sna.h"
--- src/sna/sna_video_overlay.c.orig	2025-12-24 12:33:58.427770000 +0000
+++ src/sna/sna_video_overlay.c	2025-12-24 12:34:22.973401000 +0000
@@ -23,7 +23,7 @@
  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
  **************************************************************************/
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_video.h"
--- src/sna/sna_video_sprite.c.orig	2025-12-24 12:33:58.280574000 +0000
+++ src/sna/sna_video_sprite.c	2025-12-24 12:34:22.967987000 +0000
@@ -23,7 +23,7 @@
  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
  **************************************************************************/
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_video.h"
--- src/sna/sna_video_textured.c.orig	2025-12-24 12:33:58.608170000 +0000
+++ src/sna/sna_video_textured.c	2025-12-24 12:34:22.980529000 +0000
@@ -24,7 +24,7 @@
 
  **************************************************************************/
 
-#include "config.h"
+
 
 #include "sna.h"
 #include "sna_video.h"
--- src/uxa/i830_3d.c.orig	2025-12-24 12:33:59.137316000 +0000
+++ src/uxa/i830_3d.c	2025-12-24 12:34:22.985838000 +0000
@@ -25,7 +25,7 @@
  * 
  **************************************************************************/
 
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/i830_render.c.orig	2025-12-24 12:33:59.159724000 +0000
+++ src/uxa/i830_render.c	2025-12-24 12:34:22.987954000 +0000
@@ -25,7 +25,7 @@
  *    Eric Anholt <eric@anholt.net>
  *
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/i915_3d.c.orig	2025-12-24 12:33:59.150797000 +0000
+++ src/uxa/i915_3d.c	2025-12-24 12:34:22.986565000 +0000
@@ -24,7 +24,7 @@
  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  * 
  **************************************************************************/
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/i915_render.c.orig	2025-12-24 12:33:59.160260000 +0000
+++ src/uxa/i915_render.c	2025-12-24 12:34:22.988176000 +0000
@@ -25,7 +25,7 @@
  *    Eric Anholt <eric@anholt.net>
  *
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/i915_video.c.orig	2025-12-24 12:33:59.160445000 +0000
+++ src/uxa/i915_video.c	2025-12-24 12:34:22.988328000 +0000
@@ -24,7 +24,7 @@
  *    Eric Anholt <eric@anholt.net>
  *
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/i965_3d.c.orig	2025-12-24 12:33:59.137485000 +0000
+++ src/uxa/i965_3d.c	2025-12-24 12:34:22.985982000 +0000
@@ -20,7 +20,7 @@
  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  * DEALINGS IN THE SOFTWARE.
  */
-#include "config.h"
+
 
 #include <string.h>
 
--- src/uxa/i965_render.c.orig	2025-12-24 12:33:59.195319000 +0000
+++ src/uxa/i965_render.c	2025-12-24 12:34:22.988972000 +0000
@@ -28,7 +28,7 @@
  *    Keith Packard <keithp@keithp.com>
  *
  */
-#include "config.h"
+
 
 #include <assert.h>
 #include "xorg-server.h"
--- src/uxa/i965_video.c.orig	2025-12-24 12:33:59.195982000 +0000
+++ src/uxa/i965_video.c	2025-12-24 12:34:22.989308000 +0000
@@ -25,7 +25,7 @@
  *    Keith Packard <keithp@keithp.com>
  *
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/intel.h.orig	2025-12-24 12:33:59.158953000 +0000
+++ src/uxa/intel.h	2025-12-24 12:34:22.987748000 +0000
@@ -33,7 +33,7 @@
  *   David Dawes <dawes@xfree86.org>
  *
  */
-#include "config.h"
+
 
 #if 0
 #define I830DEBUG
--- src/uxa/intel_batchbuffer.c.orig	2025-12-24 12:33:59.160780000 +0000
+++ src/uxa/intel_batchbuffer.c	2025-12-24 12:34:22.988460000 +0000
@@ -25,7 +25,7 @@
  *    Eric Anholt <eric@anholt.net>
  *
  */
-#include "config.h"
+
 
 #include <assert.h>
 #include <stdlib.h>
--- src/uxa/intel_display.c.orig	2025-12-24 12:33:59.158734000 +0000
+++ src/uxa/intel_display.c	2025-12-24 12:34:22.987587000 +0000
@@ -24,7 +24,7 @@
  *    Dave Airlie <airlied@redhat.com>
  *
  */
-#include "config.h"
+
 
 #include <sys/types.h>
 #include <sys/stat.h>
--- src/uxa/intel_dri.c.orig	2025-12-24 12:33:59.069197000 +0000
+++ src/uxa/intel_dri.c	2025-12-24 12:34:22.985474000 +0000
@@ -31,7 +31,7 @@
  *          David Dawes <dawes@xfree86.org>
  *          Keith Whitwell <keith@tungstengraphics.com>
  */
-#include "config.h"
+
 
 #include <stdio.h>
 #include <string.h>
--- src/uxa/intel_dri3.c.orig	2025-12-24 12:33:59.136953000 +0000
+++ src/uxa/intel_dri3.c	2025-12-24 12:34:22.985719000 +0000
@@ -19,7 +19,7 @@
  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
  * OF THIS SOFTWARE.
  */
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include "xf86.h"
--- src/uxa/intel_driver.c.orig	2025-12-24 12:33:59.151371000 +0000
+++ src/uxa/intel_driver.c	2025-12-24 12:34:22.986970000 +0000
@@ -32,7 +32,7 @@
  *          David Dawes <dawes@xfree86.org>
  *          Alan Hourihane <alanh@tungstengraphics.com>
  */
-#include "config.h"
+
 
 #include <assert.h>
 #include <string.h>
--- src/uxa/intel_hwmc.c.orig	2025-12-24 12:33:59.036278000 +0000
+++ src/uxa/intel_hwmc.c	2025-12-24 12:34:22.985023000 +0000
@@ -24,7 +24,7 @@
  *    Zhenyu Wang <zhenyu.z.wang@intel.com>
  *
  */
-#include "config.h"
+
 
 #define _INTEL_XVMC_SERVER_
 #include "intel.h"
--- src/uxa/intel_memory.c.orig	2025-12-24 12:33:59.090700000 +0000
+++ src/uxa/intel_memory.c	2025-12-24 12:34:22.985611000 +0000
@@ -69,7 +69,7 @@
  * binding process.  For smaller allocations, the acceleration architecture's
  * linear allocator is preferred.
  */
-#include "config.h"
+
 
 #include <assert.h>
 #include <inttypes.h>
--- src/uxa/intel_present.c.orig	2025-12-24 12:33:59.151033000 +0000
+++ src/uxa/intel_present.c	2025-12-24 12:34:22.986709000 +0000
@@ -19,7 +19,7 @@
  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
  * OF THIS SOFTWARE.
  */
-#include "config.h"
+
 
 #include <stdio.h>
 #include <string.h>
--- src/uxa/intel_uxa.c.orig	2025-12-24 12:33:59.150246000 +0000
+++ src/uxa/intel_uxa.c	2025-12-24 12:34:22.986258000 +0000
@@ -26,7 +26,7 @@
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 **************************************************************************/
-#include "config.h"
+
 
 #include "xorg-server.h"
 #include <xf86.h>
--- src/uxa/intel_uxa_video.c.orig	2025-12-24 12:33:59.036518000 +0000
+++ src/uxa/intel_uxa_video.c	2025-12-24 12:34:22.985163000 +0000
@@ -40,7 +40,7 @@
  *      Offscreen Images:
  *        Matt Sottek <matthew.j.sottek@intel.com>
  */
-#include "config.h"
+
 
 #include <inttypes.h>
 #include <math.h>
--- src/uxa/intel_video.c.orig	2025-12-24 12:33:59.150607000 +0000
+++ src/uxa/intel_video.c	2025-12-24 12:34:22.986462000 +0000
@@ -44,7 +44,7 @@
 /*
  * XXX Could support more formats.
  */
-#include "config.h"
+
 
 #include <inttypes.h>
 #include <math.h>
--- src/uxa/intel_video_overlay.c.orig	2025-12-24 12:33:59.158282000 +0000
+++ src/uxa/intel_video_overlay.c	2025-12-24 12:34:22.987135000 +0000
@@ -44,7 +44,7 @@
 /*
  * XXX Could support more formats.
  */
-#include "config.h"
+
 
 #include <inttypes.h>
 #include <math.h>
--- test/cursor-test.c.orig	2025-12-24 12:33:59.332425000 +0000
+++ test/cursor-test.c	2025-12-24 12:34:23.006201000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <stdio.h>
 #include <stdlib.h>
--- test/dri2-speed.c.orig	2025-12-24 12:33:59.333599000 +0000
+++ test/dri2-speed.c	2025-12-24 12:34:23.006335000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
--- test/dri3-test.c.orig	2025-12-24 12:33:59.331421000 +0000
+++ test/dri3-test.c	2025-12-24 12:34:23.006089000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
--- test/lowlevel-blt-bench.c.orig	2025-12-24 12:33:59.330645000 +0000
+++ test/lowlevel-blt-bench.c	2025-12-24 12:34:23.005841000 +0000
@@ -22,7 +22,7 @@
  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  * DEALINGS IN THE SOFTWARE.
  */
-#include "config.h"
+
 
 #include <stdio.h>
 #include <stdlib.h>
--- test/present-race.c.orig	2025-12-24 12:33:59.311155000 +0000
+++ test/present-race.c	2025-12-24 12:34:23.005682000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xlib-xcb.h>
--- test/present-speed.c.orig	2025-12-24 12:33:59.336575000 +0000
+++ test/present-speed.c	2025-12-24 12:34:23.006559000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
--- test/present-test.c.orig	2025-12-24 12:33:59.272695000 +0000
+++ test/present-test.c	2025-12-24 12:34:23.005331000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xlib-xcb.h>
--- test/shm-test.c.orig	2025-12-24 12:33:59.274028000 +0000
+++ test/shm-test.c	2025-12-24 12:34:23.005499000 +0000
@@ -21,7 +21,7 @@
  * SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
--- tools/backlight_helper.c.orig	2025-12-24 12:33:59.252549000 +0000
+++ tools/backlight_helper.c	2025-12-24 12:34:22.989511000 +0000
@@ -1,4 +1,4 @@
-#include "config.h"
+
 
 #include <stdio.h>
 #include <string.h>
--- tools/cursor.c.orig	2025-12-24 12:33:59.253535000 +0000
+++ tools/cursor.c	2025-12-24 12:34:22.990207000 +0000
@@ -21,7 +21,7 @@
  * IN THE SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/extensions/Xfixes.h>
--- tools/virtual.c.orig	2025-12-24 12:33:59.253378000 +0000
+++ tools/virtual.c	2025-12-24 12:34:22.990102000 +0000
@@ -21,7 +21,7 @@
  * IN THE SOFTWARE.
  *
  */
-#include "config.h"
+
 
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
