--- config.c.orig	2010-01-20 18:36:52.000000000 -0800
+++ config.c	2012-09-22 02:32:52.718116009 -0700
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
@@ -127,6 +130,21 @@
 	return s;
 }
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 800067
+/* Provide a stub getline() for older versions of FreeBSD. */
+static ssize_t getline(char **cp, size_t *lenp, FILE *f)
+{
+
+	if (*cp == NULL) {
+		*cp = malloc(4096);
+		*lenp = 4096;
+	}
+	if (fgets(*cp, *lenp, f) == NULL)
+		return (0);
+	return (strlen(*cp));
+}
+#endif
+
 int parse_config_file(const char *fn)
 {
 	FILE *f;
@@ -304,7 +322,12 @@
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
