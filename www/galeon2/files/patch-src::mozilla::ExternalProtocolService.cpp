
$FreeBSD$

--- src/mozilla/ExternalProtocolService.cpp.orig	Sat May 18 02:03:19 2002
+++ src/mozilla/ExternalProtocolService.cpp	Fri May 24 16:56:19 2002
@@ -16,7 +16,14 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include "config.h"
+
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#endif
 #include <gtk/gtk.h>
 
 #include "ExternalProtocolService.h"
