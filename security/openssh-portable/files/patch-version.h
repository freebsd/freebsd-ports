--- version.h.orig	2009-02-22 18:09:26.000000000 -0600
+++ version.h	2010-01-14 00:09:24.057609101 -0600
@@ -1,6 +1,12 @@
-/* $OpenBSD: version.h,v 1.55 2009/02/23 00:06:15 djm Exp $ */
+/* $FreeBSD$ */
 
-#define SSH_VERSION	"OpenSSH_5.2"
+#ifndef SSH_VERSION
 
-#define SSH_PORTABLE	"p1"
-#define SSH_RELEASE	SSH_VERSION SSH_PORTABLE
+#define SSH_VERSION             (ssh_version_get())
+#define SSH_RELEASE             (ssh_version_get())
+#define SSH_VERSION_BASE        "OpenSSH_%%SSH_VERSION%%"
+#define SSH_VERSION_ADDENDUM    "FreeBSD-%%ADDENDUM%%"
+
+const char *ssh_version_get(void);
+void ssh_version_set_addendum(const char *);
+#endif /* SSH_VERSION */
