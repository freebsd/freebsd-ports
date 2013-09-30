--- libavdevice/bktr.c.orig	2012-01-22 14:41:15.000000000 +0100
+++ libavdevice/bktr.c	2012-01-22 16:07:07.873280412 +0100
@@ -24,6 +24,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char u_char;
+typedef unsigned short        u_short;
+typedef unsigned int  u_int;
+typedef unsigned long u_long;
+
 #include "libavformat/internal.h"
 #include "libavutil/log.h"
 #include "libavutil/opt.h"
