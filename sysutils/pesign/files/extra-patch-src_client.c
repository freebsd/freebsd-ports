--- src/client.c.orig	2014-10-24 19:51:06 UTC
+++ src/client.c
@@ -47,6 +47,49 @@ static struct {
 	{FLAG_LIST_END, NULL},
 };
 
+#if defined(__FreeBSD__) && __FreeBSD__ < 10
+/*-
+ * Copyright (c) 2013 Niclas Zeising
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ *
+ * $FreeBSD: head/lib/libc/string/strchrnul.c 288004 2015-09-20 03:51:15Z rodrigc
+ */
+
+static char *
+strchrnul(const char *p, int ch)
+{
+	char c;
+
+	c = ch;
+	for (;; ++p) {
+		if (*p == c || *p == '\0')
+			return ((char *)p);
+	}
+	/* NOTREACHED */
+}
+#endif
+
 static void
 print_flag_name(FILE *f, int flag)
 {
