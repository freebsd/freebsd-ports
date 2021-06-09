--- src/utils/os_unix.c.orig	2021-06-02 14:11:18.000000000 -0700
+++ src/utils/os_unix.c	2021-06-07 16:07:39.152547000 -0700
@@ -464,9 +464,9 @@
 int os_fdatasync(FILE *stream)
 {
 	if (!fflush(stream)) {
-#ifdef __linux__
+#if defined __FreeBSD__ || defined __linux__
 		return fdatasync(fileno(stream));
-#else /* !__linux__ */
+#else /* !__linux__ && !__FreeBSD__ */
 #ifdef F_FULLFSYNC
 		/* OS X does not implement fdatasync(). */
 		return fcntl(fileno(stream), F_FULLFSYNC);
