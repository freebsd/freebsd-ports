--- server/misc.c.orig	Tue Jan  9 08:28:04 1996
+++ server/misc.c	Fri Jan 25 06:16:44 2002
@@ -965,6 +965,27 @@
 **		none.
 */
 
+
+#if defined(BSD_44)
+#include <stdlib.h>
+
+int
+getla( void )
+{
+	double avenrun[3];
+	int rc;
+
+        rc = getloadavg( avenrun, 1 );
+	if ( rc == -1 )
+		return 1;
+# ifdef FSCALE
+	return ((int) (avenrun[0] + FSCALE/2) >> FSHIFT);
+# else
+	return ((int) (avenrun[0] + 0.5));
+# endif
+}
+
+#else
 #if defined(USG) && !defined(SVR4)
 int
 getla()
@@ -1058,4 +1079,5 @@
 # endif
 }
 #endif
+#endif /* BSD_44 */
 #endif /* LOAD */
