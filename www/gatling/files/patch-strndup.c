--- /dev/null	2009-04-10 17:44:00.000000000 +0200
+++ trystrndup.c	2009-04-10 17:01:00.000000000 +0200
@@ -0,0 +1,6 @@
+#include <string.h>
+int main() {
+char* s;
+s=strndup("foo",3);
+return 0;
+}
--- /dev/null	2009-04-10 16:55:00.000000000 +0200
+++ strndup.c	2009-01-08 10:50:20.000000000 +0100
@@ -0,0 +1,53 @@
+/*      $NetBSD: strndup.c,v 1.3 2007/01/14 23:41:24 cbiere Exp $       */
+
+/*
+ * Copyright (c) 1988, 1993
+ *	The Regents of the University of California.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 4. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+#include <sys/cdefs.h>
+__FBSDID("$FreeBSD: /tmp/pcvs/ports/www/gatling/files/Attic/patch-strndup.c,v 1.1 2009-05-28 17:21:46 dhn Exp $");
+
+#include <stddef.h>
+#include <stdlib.h>
+#include <string.h>
+
+char *
+strndup(const char *str, size_t n)
+{
+	size_t len;
+	char *copy;
+
+	for (len = 0; len < n && str[len]; len++)
+		continue;
+
+	if ((copy = malloc(len + 1)) == NULL)
+		return (NULL);
+	memcpy(copy, str, len);
+	copy[len] = '\0';
+	return (copy);
+}
