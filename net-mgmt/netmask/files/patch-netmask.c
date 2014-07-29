--- netmask.c.orig	Mon Nov 20 00:22:41 2000
+++ netmask.c	Mon Nov 20 00:22:58 2000
@@ -17,15 +17,15 @@
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <getopt.h>
 #include <netdb.h>
-#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 #include "errors.h"
 
 struct addrmask {
