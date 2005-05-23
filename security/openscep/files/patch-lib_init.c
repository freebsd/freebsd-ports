--- lib/init.c.orig	Wed Feb 20 02:40:06 2002
+++ lib/init.c	Thu May 19 16:23:01 2005
@@ -21,6 +21,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#include <openscep_err.h>
 
 #define	TMPPATH	"/var/tmp/openscep"
 
@@ -66,6 +67,11 @@
 	ERR_load_crypto_strings();
 	if (debug)
 		fprintf(stderr, "%s:%d: crypto strings loaded\n", __FILE__,
+			__LINE__);
+
+	ERR_load_OPENSCEP_strings();
+	if (debug)
+		fprintf(stderr, "%s:%d: openscep strings loaded\n", __FILE__,
 			__LINE__);
 
 	/* add the encryption algorithms available			*/
