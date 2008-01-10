--- src/hx.h.orig	Tue Apr  8 05:05:31 2003
+++ src/hx.h	Fri Jan 11 01:49:32 2008
@@ -172,10 +172,6 @@
 
 extern char **hxd_environ;
 
-#if !defined(HAVE_INET_NTOA_R)
-extern int inet_ntoa_r (struct in_addr in, char *buf, size_t buflen);
-#endif
-
 #ifndef HAVE_LOCALTIME_R
 extern struct tm *localtime_r (const time_t *t, struct tm *tm);
 #endif
