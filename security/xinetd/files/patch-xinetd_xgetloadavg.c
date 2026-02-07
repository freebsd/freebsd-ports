--- xinetd/xgetloadavg.c.orig	2012-05-09 16:03:17 UTC
+++ xinetd/xgetloadavg.c
@@ -87,6 +87,21 @@ double xgetloadavg(void)
 #endif /* HAVE_KSTAT */
 #endif /* solaris */
 
+#ifdef __FreeBSD__
+
+#include <stdio.h>
+#include <sys/param.h>
+#include <sys/fcntl.h>
+
+double xgetloadavg ()
+{
+	double ret[3];
+
+	getloadavg (ret, sizeof (ret) / sizeof (ret[0]));
+
+	return ret[0];
+}
+#endif /* __FreeBSD__ */
 
 #if defined(bsdi) || defined(__APPLE__)
 #include <stdlib.h>
