--- posix.c.orig	2024-01-17 22:35:53 UTC
+++ posix.c
@@ -465,7 +465,11 @@ PHP_FUNCTION(posix_ttyname)
 #if defined(ZTS) && defined(HAVE_TTYNAME_R) && defined(_SC_TTY_NAME_MAX)
 	buflen = sysconf(_SC_TTY_NAME_MAX);
 	if (buflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+		buflen = sysconf(_SC_PAGESIZE);
+#else
 		RETURN_FALSE;
+#endif
 	}
 	p = emalloc(buflen);
 
@@ -728,7 +732,11 @@ PHP_FUNCTION(posix_getgrnam)
 #if defined(ZTS) && defined(HAVE_GETGRNAM_R) && defined(_SC_GETGR_R_SIZE_MAX)
 	buflen = sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (buflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+		buflen = sysconf(_SC_PAGESIZE);
+#else
 		RETURN_FALSE;
+#endif
 	}
 	buf = emalloc(buflen);
 try_again:
@@ -784,7 +792,11 @@ PHP_FUNCTION(posix_getgrgid)
 
 	grbuflen = sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (grbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+		grbuflen = sysconf(_SC_PAGESIZE);
+#else
 		RETURN_FALSE;
+#endif
 	}
 
 	grbuf = emalloc(grbuflen);
@@ -858,7 +870,11 @@ PHP_FUNCTION(posix_getpwnam)
 #if defined(ZTS) && defined(_SC_GETPW_R_SIZE_MAX) && defined(HAVE_GETPWNAM_R)
 	buflen = sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (buflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+		buflen = sysconf(_SC_PAGESIZE);
+#else
 		RETURN_FALSE;
+#endif
 	}
 	buf = emalloc(buflen);
 	pw = &pwbuf;
@@ -913,7 +929,11 @@ PHP_FUNCTION(posix_getpwuid)
 #if defined(ZTS) && defined(_SC_GETPW_R_SIZE_MAX) && defined(HAVE_GETPWUID_R)
 	pwbuflen = sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (pwbuflen < 1) {
+#if defined(__FreeBSD__) && defined(_SC_PAGESIZE)
+		pwbuflen = sysconf(_SC_PAGESIZE);
+#else
 		RETURN_FALSE;
+#endif
 	}
 	pwbuf = emalloc(pwbuflen);
 
