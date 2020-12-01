--- monitord.h.orig	2003-01-16 18:22:54 UTC
+++ monitord.h
@@ -48,8 +48,7 @@ ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
 #include <netdb.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-
-int	HUP;  // Variable used to hold SIGHUP state
+#include <sys/param.h>
 
 typedef enum bool_enum_t {
 	FALSE,
