--- pen.c.orig	Tue Nov 13 21:43:24 2001
+++ pen.c	Tue Nov 13 21:43:37 2001
@@ -17,6 +17,7 @@
    MA 02111-1307, USA.
 */
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <errno.h>
@@ -31,7 +32,6 @@
 #include <sys/wait.h>
 #include <sys/resource.h>
 #include <sys/socket.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
