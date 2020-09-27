Otherwise realpath(3) declaration isn't found: https://github.com/rpm-software-management/librepo/issues/202

--- librepo/yum.c.orig	2020-09-27 10:18:54 UTC
+++ librepo/yum.c
@@ -18,8 +18,8 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
-#define _POSIX_SOURCE
-#define _DEFAULT_SOURCE
+//#define _POSIX_SOURCE
+//#define _DEFAULT_SOURCE
 #define  BITS_IN_BYTE 8
 
 #include <stdio.h>
