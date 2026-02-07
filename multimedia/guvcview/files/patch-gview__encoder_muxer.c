--- gview_encoder/muxer.c.orig	2024-11-02 13:15:33 UTC
+++ gview_encoder/muxer.c
@@ -30,7 +30,7 @@ Inc., 59 Temple Place, Suite 330, Boston, MA  02111-13
 #include <unistd.h>
 // #include <errno.h>
 #include <assert.h>
-#include <sys/statfs.h>
+#include <sys/mount.h>
 /* support for internationalization - i18n */
 #include <libintl.h>
 #include <locale.h>
