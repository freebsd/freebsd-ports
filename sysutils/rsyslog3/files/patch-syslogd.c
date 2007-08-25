--- ./syslogd.c.orig	2007-08-25 20:07:21.000000000 +0400
+++ ./syslogd.c	2007-08-25 20:08:39.000000000 +0400
@@ -86,7 +86,6 @@
 #include "rsyslog.h"
 
 #ifdef __FreeBSD__
-#define	BSD
 #endif
 
 /* change the following setting to e.g. 32768 if you would like to
@@ -1877,6 +1876,11 @@
 	return iRet;
 }
 
+size_t strnlen (const char *string, size_t maxlen)
+{
+	const char *end = memchr (string, '\0', maxlen);
+	return end ? (size_t) (end - string) : maxlen;
+}
 
 /* rgerhards, 2005-10-24: crunch_list is called only during option processing. So
  * it is never called once rsyslogd is running (not even when HUPed). This code
