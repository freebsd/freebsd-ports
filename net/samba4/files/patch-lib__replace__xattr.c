--- lib/replace/xattr.c.orig	2013-11-19 12:05:06.297639060 +0000
+++ lib/replace/xattr.c	2013-11-19 12:05:15.450326063 +0000
@@ -25,6 +25,7 @@
    License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
 
+#define UID_WRAPPER_NOT_REPLACE
 #include "replace.h"
 #include "system/filesys.h"
 #include "system/dir.h"
