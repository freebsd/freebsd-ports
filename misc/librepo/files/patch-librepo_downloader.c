https://github.com/rpm-software-management/librepo/issues/200

--- librepo/downloader.c.orig	2020-08-22 20:15:59 UTC
+++ librepo/downloader.c
@@ -18,9 +18,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
-#define _XOPEN_SOURCE   500 // Because of fdopen() and ftruncate()
-#define _DEFAULT_SOURCE     // Because of futimes()
-#define _BSD_SOURCE         // Because of futimes()
+#if __FreeBSD__
+//#define _XOPEN_SOURCE   500 // Because of fdopen() and ftruncate()
+//#define _DEFAULT_SOURCE     // Because of futimes()
+//#define _BSD_SOURCE         // Because of futimes()
+#endif
 
 #include <glib.h>
 #include <assert.h>
@@ -31,7 +33,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/time.h>
-#include <sys/xattr.h>
+#include "xattr.h"
 #include <fcntl.h>
 #include <curl/curl.h>
 
