--- pfutils.c.orig	2018-06-06 08:53:18 UTC
+++ pfutils.c
@@ -15,6 +15,8 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifndef NO_PF /* No need of PF support */
+
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
@@ -254,3 +256,4 @@ pfmsg(char c, struct lease *lp)
 		break;
 	}
 }
+#endif /* NO_PF */
