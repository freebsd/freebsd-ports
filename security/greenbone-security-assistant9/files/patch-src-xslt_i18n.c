--- src/xslt_i18n.c.orig	2015-08-03 08:55:58 UTC
+++ src/xslt_i18n.c
@@ -23,6 +23,7 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
+#define _WITH_GETLINE
 #include "xslt_i18n.h"
 #include <assert.h>
 #include <dirent.h>
