--- libavdevice/oss_audio.c.orig	2015-01-06 18:58:58 UTC
+++ libavdevice/oss_audio.c
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
