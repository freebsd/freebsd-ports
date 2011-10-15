--- ./config.c.orig	2009-12-15 07:18:40.000000000 -0500
+++ ./config.c	2011-10-14 22:36:47.000000000 -0400
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
@@ -126,6 +129,21 @@
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
