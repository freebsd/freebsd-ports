--- libavdevice/oss.c.orig	2015-06-19 20:44:50 UTC
+++ libavdevice/oss.c
@@ -19,6 +19,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char	u_char;
+typedef unsigned short	u_short;
+typedef unsigned int	u_int;
+typedef unsigned long	u_long;
+
 #include "config.h"
 
 #include <string.h>
