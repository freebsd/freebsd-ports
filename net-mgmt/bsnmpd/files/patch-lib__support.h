--- lib/support.h	Mon Feb 27 13:03:16 2006
+++ lib/support.h	Fri Apr 21 22:14:27 2006
@@ -36,6 +36,13 @@
 
 #include <sys/cdefs.h>
 
+#ifndef HAVE_MIB_LINKSTATE
+#include <net/if_media.h>
+#define LINK_STATE_UNKNOWN	0
+#define LINK_STATE_DOWN	1
+#define LINK_STATE_UP  	2
+#endif
+
 #ifndef HAVE_ERR_H
 void err(int, const char *, ...) __printflike(2, 3) __dead2;
 void errx(int, const char *, ...) __printflike(2, 3) __dead2;
