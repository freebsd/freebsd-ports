--- server/common.h.orig	Thu Nov 17 19:15:18 1994
+++ server/common.h	Mon Nov  4 05:32:45 2002
@@ -148,10 +148,15 @@
 
 #define	putline(s)	fputs((s), stdout); putchar('\r'); putchar('\n');
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#include <unistd.h>
+#else
 extern	int	errno;
 
 extern	char	*gets(), *fgets();
 extern	char	*mktemp();
+#endif
 extern	FILE	*open_valid_art();
 extern	FILE	*openartbyid();
 extern	char	*gethistent();
@@ -161,7 +166,11 @@
 void debugup(), debugdown();
 #endif
 #ifdef SETPROCTITLE
+#ifdef HAVE_PROCTITLE
+#include <libutil.h>
+#else
 void setproctitle();
+#endif
 #endif
 
 extern	char	spooldir[];
