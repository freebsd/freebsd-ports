--- xmit/remote.c.orig	Tue Jan  9 08:28:03 1996
+++ xmit/remote.c	Mon Nov  4 05:59:42 2002
@@ -71,7 +71,13 @@
 char	*sfgets();
 char	*rfgets();
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#include <unistd.h>
+#include <string.h>
+#else
 extern	int	errno;
+#endif
 extern	char	Debug;
 extern	char	*errmsg();
 extern	char	*strcpy();
@@ -403,7 +409,7 @@
 ** with appropriate RFC822 filtering (e.g. CRLF line termination,
 ** and dot escaping). Return FALSE if something went wrong.
 */
-sendfile(fp)
+my_sendfile(fp)
 FILE	*fp;
 {
 	register int	c;
