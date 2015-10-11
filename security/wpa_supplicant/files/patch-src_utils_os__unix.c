--- src/utils/os_unix.c.orig	2015-09-27 19:02:05 UTC
+++ src/utils/os_unix.c
@@ -214,17 +214,42 @@ static int os_daemon(int nochdir, int no
 #define os_daemon daemon
 #endif /* __APPLE__ */
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define FREE_DRAGON
+#include <err.h>
+#include <libutil.h>
+#include <stdint.h>
+#endif /* __FreeBSD__ || __DragonFly__ */
 
 int os_daemonize(const char *pid_file)
 {
 #if defined(__uClinux__) || defined(__sun__)
 	return -1;
 #else /* defined(__uClinux__) || defined(__sun__) */
+#ifdef FREE_DRAGON
+	pid_t otherpid;
+	struct pidfh *pfh;
+
+	pfh = pidfile_open(pid_file, 0600, &otherpid);
+	if (pfh == NULL) {
+		if (errno == EEXIST) {
+			errx(1, "Daemon already running, pid: %jd.",
+			    (intmax_t)otherpid);
+		}
+		warn("Cannot open or create pidfile.");
+	}
+#endif /* FREE_DRAGON */
 	if (os_daemon(0, 0)) {
 		perror("daemon");
+#ifdef FREE_DRAGON
+		pidfile_remove(pfh);
+#endif /* FREE_DRAGON */
 		return -1;
 	}
 
+#ifdef FREE_DRAGON
+	pidfile_write(pfh);
+#else
 	if (pid_file) {
 		FILE *f = fopen(pid_file, "w");
 		if (f) {
@@ -232,6 +257,7 @@ int os_daemonize(const char *pid_file)
 			fclose(f);
 		}
 	}
+#endif /* FREE_DRAGON */
 
 	return -0;
 #endif /* defined(__uClinux__) || defined(__sun__) */
@@ -384,7 +410,7 @@ int os_setenv(const char *name, const ch
 
 int os_unsetenv(const char *name)
 {
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__) || \
+#if defined(FREE_DRAGON) || defined(__NetBSD__) || defined(__APPLE__) || \
     defined(__OpenBSD__)
 	unsetenv(name);
 	return 0;
@@ -445,7 +471,9 @@ int os_file_exists(const char *fname)
 int os_fdatasync(FILE *stream)
 {
 	if (!fflush(stream)) {
-#ifndef __MACH__
+#ifdef FREE_DRAGON
+		return fsync(fileno(stream));
+#elif !defined __MACH__
 		return fdatasync(fileno(stream));
 #else /* __MACH__ */
 #ifdef F_FULLFSYNC
