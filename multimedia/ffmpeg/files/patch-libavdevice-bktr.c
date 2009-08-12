--- libavdevice/bktr.c.orig	2009-05-15 17:34:55.000000000 +0200
+++ libavdevice/bktr.c	2009-05-15 17:38:01.000000000 +0200
@@ -24,6 +24,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char	u_char;
+typedef unsigned short	u_short;
+typedef unsigned int	u_int;
+typedef unsigned long	u_long;
+
 #define _BSD_SOURCE 1
 #include "libavformat/avformat.h"
 #if HAVE_DEV_BKTR_IOCTL_METEOR_H && HAVE_DEV_BKTR_IOCTL_BT848_H
