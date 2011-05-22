--- relayctl/parser.c.orig	2011-05-19 10:56:49.000000000 +0200
+++ relayctl/parser.c	2011-05-22 10:51:26.683383150 +0200
@@ -18,7 +18,11 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#else
 #include <sys/types.h>
+#endif
 #include <sys/socket.h>
 #include <sys/queue.h>
 
@@ -87,7 +91,9 @@
 	{KEYWORD,	"hosts",	SHOW_HOSTS,	NULL},
 	{KEYWORD,	"redirects",	SHOW_RDRS,	NULL},
 	{KEYWORD,	"relays",	SHOW_RELAYS,	NULL},
+#ifndef __FreeBSD__
 	{KEYWORD,	"routers",	SHOW_ROUTERS,	NULL},
+#endif
 	{KEYWORD,	"sessions",	SHOW_SESSIONS,	NULL},
 	{ENDTOKEN,	"",		NONE,		NULL}
 };
