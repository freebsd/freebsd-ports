--- etunnel.h.orig	Wed May  5 21:10:21 2004
+++ etunnel.h	Wed May  5 21:10:36 2004
@@ -23,11 +23,11 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdarg.h>
 #include <sys/socket.h>
-#include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/time.h>
 #include <netinet/in.h>
