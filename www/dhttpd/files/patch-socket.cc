--- src/socket.cc.orig	Mon Jun 24 15:12:40 2002
+++ src/socket.cc	Mon Jun 24 15:13:03 2002
@@ -17,6 +17,7 @@
  *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
+#include <sys/types.h>
 #include <errno.h>
 #include <netdb.h>
 #include <netinet/in.h>
@@ -24,7 +25,6 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -149,7 +149,7 @@
 	do
 	{
 		cSidLen = sizeof( cSid );
-		s = accept( sock, &cSid, &cSidLen );
+		s = accept( sock, &cSid, (socklen_t *) &cSidLen );
 	}
 	while( s==-1 );
 
