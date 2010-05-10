--- egg/egg-unix-credentials.c.orig	2010-01-13 00:21:23.000000000 -0500
+++ egg/egg-unix-credentials.c	2010-01-13 00:25:46.000000000 -0500
@@ -27,6 +27,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <sys/uio.h>
 #include <sys/un.h>
 #include <errno.h>
@@ -37,6 +38,33 @@
 #include <ucred.h>
 #endif
 
+#if __FreeBSD_version < 701101
+static char *
+strndup (const char *s, size_t n)
+{
+	size_t nAvail;
+	char *p;
+
+	if (s == NULL)
+		return NULL;
+
+	if (memchr (s, '\0', n) != NULL) {
+		nAvail = strlen(s);
+		if (nAvail > n)
+			nAvail = n;
+	} else{
+		nAvail = n;
+	}
+	p = malloc (nAvail + 1);
+	if (p == NULL)
+		return NULL;
+	memcpy (p, s, nAvail);
+	p[nAvail] = '\0';
+
+	return p;
+}
+#endif
+
 int
 egg_unix_credentials_read (int sock, pid_t *pid, uid_t *uid)
 {
