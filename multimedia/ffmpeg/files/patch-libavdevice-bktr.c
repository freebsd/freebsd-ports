--- libavdevice/bktr.c.orig	2015-06-19 20:44:50 UTC
+++ libavdevice/bktr.c
@@ -24,6 +24,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char u_char;
+typedef unsigned short        u_short;
+typedef unsigned int  u_int;
+typedef unsigned long u_long;
+
 #include "libavformat/internal.h"
 #include "libavutil/internal.h"
 #include "libavutil/log.h"
