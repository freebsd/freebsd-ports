--- posix.c.orig	Fri Feb 23 08:23:14 2007
+++ posix.c	Fri Feb 23 08:27:53 2007
@@ -838,7 +838,7 @@
 #if defined(ZTS) && defined(HAVE_GETGRNAM_R) && defined(_SC_GETGR_R_SIZE_MAX)
 	buflen = sysconf(_SC_GETGR_R_SIZE_MAX);
 	if (buflen < 1) {
-		RETURN_FALSE;
+		buflen = 1024;
 	}
 	buf = emalloc(buflen);
 	g = &gbuf;
@@ -887,6 +887,9 @@
 #ifdef HAVE_GETGRGID_R
 	
 	grbuflen = sysconf(_SC_GETGR_R_SIZE_MAX);
+	if (grbuflen < 1) {
+		grbuflen = 1024;
+	}
 	grbuf = emalloc(grbuflen);
 
 	ret = getgrgid_r(gid, &_g, grbuf, grbuflen, &retgrptr);
@@ -951,7 +954,7 @@
 #if defined(ZTS) && defined(_SC_GETPW_R_SIZE_MAX) && defined(HAVE_GETPWNAM_R)
 	buflen = sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (buflen < 1) {
-		RETURN_FALSE;
+		buflen = 1024;
 	}
 	buf = emalloc(buflen);
 	pw = &pwbuf;
@@ -1000,7 +1003,7 @@
 #if defined(ZTS) && defined(_SC_GETPW_R_SIZE_MAX) && defined(HAVE_GETPWUID_R)
 	pwbuflen = sysconf(_SC_GETPW_R_SIZE_MAX);
 	if (pwbuflen < 1) {
-		RETURN_FALSE;
+		pwbuflen = 1024;
 	}
 	pwbuf = emalloc(pwbuflen);
 
