--- protocol.c.orig	Wed Jun 13 19:03:11 2001
+++ protocol.c	Sun Dec 30 14:37:45 2001
@@ -16,7 +16,11 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 #include <stdio.h>
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <string.h>
@@ -24,7 +28,6 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/types.h>
 #include <ctype.h>
 #include <time.h>
 
