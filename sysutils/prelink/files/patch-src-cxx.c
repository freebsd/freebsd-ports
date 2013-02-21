diff -Nur src/cxx.c src/cxx.c
--- src/cxx.c	2013-02-19 23:54:34.000000000 +0200
+++ src/cxx.c	2013-02-19 23:50:31.000000000 +0200
@@ -16,7 +16,9 @@
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #include <config.h>
+#if HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <assert.h>
 #include <errno.h>
 #include <error.h>
