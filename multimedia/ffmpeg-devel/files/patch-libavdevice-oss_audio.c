--- libavdevice/oss_audio.c.orig	2009-05-15 17:38:35.000000000 +0200
+++ libavdevice/oss_audio.c	2009-05-15 17:41:27.000000000 +0200
@@ -19,6 +19,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char	u_char;
+typedef unsigned short	u_short;
+typedef unsigned int	u_int;
+typedef unsigned long	u_long;
+
 #include "config.h"
 #include <stdlib.h>
 #include <stdio.h>
