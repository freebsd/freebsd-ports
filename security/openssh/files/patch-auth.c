--- auth.c.orig	Fri Mar  1 14:12:10 2002
+++ auth.c	Fri Mar  8 20:57:17 2002
@@ -25,7 +25,77 @@
 #include "includes.h"
 RCSID("$OpenBSD: auth.c,v 1.35 2002/03/01 13:12:10 markus Exp $");
 
+#if defined(__FreeBSD__) && __FreeBSD__ <= 3
+/*
+ * Copyright (c) 1997 Todd C. Miller <Todd.Miller@courtesan.com>
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
+ * 3. The name of the author may not be used to endorse or promote products
+ *    derived from this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
+ * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
+ * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
+ * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
+ * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
+ * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
+ * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
+ * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
+ * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
+ * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ */
+
+char *
+dirname(path)
+	const char *path;
+{
+	static char bname[MAXPATHLEN];
+	register const char *endp;
+
+	/* Empty or NULL string gets treated as "." */
+	if (path == NULL || *path == '\0') {
+		(void)strcpy(bname, ".");
+		return(bname);
+	}
+
+	/* Strip trailing slashes */
+	endp = path + strlen(path) - 1;
+	while (endp > path && *endp == '/')
+		endp--;
+
+	/* Find the start of the dir */
+	while (endp > path && *endp != '/')
+		endp--;
+
+	/* Either the dir is "/" or there are no slashes */
+	if (endp == path) {
+		(void)strcpy(bname, *endp == '/' ? "/" : ".");
+		return(bname);
+	} else {
+		do {
+			endp--;
+		} while (endp > path && *endp == '/');
+	}
+
+	if (endp - path + 2 > sizeof(bname)) {
+		errno = ENAMETOOLONG;
+		return(NULL);
+	}
+	(void)strncpy(bname, path, endp - path + 1);
+	bname[endp - path + 1] = '\0';
+	return(bname);
+}
+#else
 #include <libgen.h>
+#endif
 
 #include "xmalloc.h"
 #include "match.h"
@@ -141,6 +211,16 @@
 			}
 		ga_free();
 	}
+#ifdef __FreeBSD__  
+	/* Fail if the account's expiration time has passed. */
+	if (pw->pw_expire != 0) {
+		struct timeval tv;
+
+		(void)gettimeofday(&tv, NULL);
+		if (tv.tv_sec >= pw->pw_expire)
+			return 0;
+	}
+#endif /* __FreeBSD__ */
 	/* We found no reason not to let this user try to log on... */
 	return 1;
 }
