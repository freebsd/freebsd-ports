- Prefer system PATH_MAX
- Add OpenPAM support
- Relax O_PATH optimization

--- pam_xdg.c.orig	2021-03-29 22:50:34 UTC
+++ pam_xdg.c
@@ -52,6 +52,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <limits.h> /* PATH_MAX */
 #include <pwd.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -60,11 +61,29 @@
 #include <unistd.h>
 
 #include <security/pam_modules.h>
+#if __has_include(<security/pam_ext.h>)
 #include <security/pam_ext.h>
+#else
+#include <security/pam_appl.h>
+/* From freebsd-src/sys/contrib/openzfs/contrib/pam_zfs_key/pam_zfs_key.c */
+static void
+pam_syslog(pam_handle_t *pamh __unused, int loglevel, const char *fmt, ...)
+{
+	va_list args;
+	va_start(args, fmt);
+	vsyslog(loglevel, fmt, args);
+	va_end(args);
+}
+#endif
 
 /* _XOPEN_PATH_MAX POSIX 2008/Cor 1-2013 */
 #ifndef PATH_MAX
 # define PATH_MAX 1024
+#endif
+
+/* Linux extension adopted by FreeBSD 13.1 */
+#ifndef O_PATH
+# define O_PATH 0
 #endif
 
 static int a_xdg(int isopen, pam_handle_t *pamh, int flags, int argc,
