--- relayctl/parser.c.orig	Wed May 30 07:41:48 2007
+++ relayctl/parser.c	Mon Jan  7 21:32:16 2008
@@ -18,7 +18,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/queue.h>
 #include <netinet/in.h>
@@ -118,6 +118,9 @@
 };
 
 static struct parse_result	res;
+
+const struct token      *match_token(const char *, const struct token []);
+void                     show_valid_args(const struct token []);
 
 struct parse_result *
 parse(int argc, char *argv[])
