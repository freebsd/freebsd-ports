--- testserver.c.orig	Wed Jun 13 19:05:19 2001
+++ testserver.c	Sun Dec 30 14:36:07 2001
@@ -15,10 +15,13 @@
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 
 
