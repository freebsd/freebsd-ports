--- config.c.orig	2010-01-21 02:36:52 UTC
+++ config.c
@@ -18,6 +18,9 @@
    Author: Andi Kleen 
 */
 #define _GNU_SOURCE 1
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
@@ -304,7 +307,12 @@ int config_trigger(const char *header, c
 	s = config_string(header, name);
 	if (s) { 
 		/* no $PATH */
+#ifdef __Linux_
 		if (trigger_check(s) != 0) {
+#endif
+#ifdef __FreeBSD__
+		if (access(s, R_OK|X_OK) != 0) {
+#endif
 			SYSERRprintf("Trigger `%s' not executable\n", s);
 			exit(1);
 		}
