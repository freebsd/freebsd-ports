--- client.c.orig	Wed Jun 13 19:04:37 2001
+++ client.c	Sun Dec 30 14:35:28 2001
@@ -15,7 +15,9 @@
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <openssl/dsa.h>
 
