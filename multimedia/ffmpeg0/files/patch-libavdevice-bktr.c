--- libavdevice/bktr.c.orig	2011-06-21 21:29:25.000000000 +0200
+++ libavdevice/bktr.c	2011-06-23 13:39:44.160881669 +0200
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
