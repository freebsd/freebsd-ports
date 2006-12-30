--- src/strndup.c.orig	Sat Dec 23 02:49:09 2006
+++ src/strndup.c	Sat Dec 23 13:36:14 2006
@@ -0,0 +1,13 @@
+#include <sys/types.h>
+#include <stdlib.h>
+#include <string.h>
+#include "strndup.h"
+
+char *strndup(const char *s, size_t n) {
+	char *dup = (char *)malloc(n+1);
+	if(dup) {
+		strncpy(dup,s,n);
+		dup[n]= '\0';
+	}
+	return dup;
+}
