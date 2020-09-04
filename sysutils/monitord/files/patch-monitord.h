--- monitord.h.orig	2003-01-16 18:22:54 UTC
+++ monitord.h
@@ -49,8 +49,6 @@ ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
 #include <netinet/in.h>
 #include <arpa/inet.h>
 
-int	HUP;  // Variable used to hold SIGHUP state
-
 typedef enum bool_enum_t {
 	FALSE,
 	TRUE,
