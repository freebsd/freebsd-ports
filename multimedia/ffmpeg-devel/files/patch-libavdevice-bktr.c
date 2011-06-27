--- libavdevice/bktr.c.orig	2011-06-25 04:32:49.000000000 +0200
+++ libavdevice/bktr.c	2011-06-25 10:11:19.281738648 +0200
@@ -24,6 +24,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char	u_char;
+typedef unsigned short	u_short;
+typedef unsigned int	u_int;
+typedef unsigned long	u_long;
+
 #include "libavutil/log.h"
 #include "libavutil/opt.h"
 #include "libavutil/parseutils.h"
