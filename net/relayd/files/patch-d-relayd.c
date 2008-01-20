--- relayd/relayd.c.orig	2008-01-14 10:00:21.487354557 +0900
+++ relayd/relayd.c	2008-01-14 16:44:45.705572691 +0900
@@ -16,7 +16,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
@@ -36,7 +36,7 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <pwd.h>
-#include <sha1.h>
+#include <sha.h>
 #include <md5.h>
 
 #include <openssl/ssl.h>
@@ -943,7 +943,7 @@
 {
 	switch (type) {
 	case DIGEST_SHA1:
-		return (SHA1Data(data, len, buf));
+		return (SHA1_Data(data, len, buf));
 		break;
 	case DIGEST_MD5:
 		return (MD5Data(data, len, buf));
