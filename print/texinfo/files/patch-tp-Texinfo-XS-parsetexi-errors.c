--- tp/Texinfo/XS/parsetexi/errors.c.orig	2019-08-25 17:11:45 UTC
+++ tp/Texinfo/XS/parsetexi/errors.c
@@ -14,7 +14,9 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
 #include <config.h>
+#if defined(HAVE_LIBINTL_H)
 #include <libintl.h>
+#endif
 
 #include <stdlib.h>
 #include <stdarg.h>
