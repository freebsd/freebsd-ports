--- lib/kadm5/logger.c.orig	Mon Jun 19 16:33:36 2006
+++ lib/kadm5/logger.c	Wed Apr  4 13:53:04 2007
@@ -45,7 +45,7 @@
 #include <varargs.h>
 #endif	/* HAVE_STDARG_H */
 
-#define	KRB5_KLOG_MAX_ERRMSG_SIZE	1024
+#define	KRB5_KLOG_MAX_ERRMSG_SIZE	2048
 #ifndef	MAXHOSTNAMELEN
 #define	MAXHOSTNAMELEN	256
 #endif	/* MAXHOSTNAMELEN */
@@ -261,7 +261,9 @@
 #endif	/* HAVE_SYSLOG */
 
     /* Now format the actual message */
-#if	HAVE_VSPRINTF
+#if	HAVE_VSNPRINTF
+    vsnprintf(cp, sizeof(outbuf) - (cp - outbuf), actual_format, ap);
+#elif	HAVE_VSPRINTF
     vsprintf(cp, actual_format, ap);
 #else	/* HAVE_VSPRINTF */
     sprintf(cp, actual_format, ((int *) ap)[0], ((int *) ap)[1],
@@ -850,7 +852,9 @@
     syslogp = &outbuf[strlen(outbuf)];
 
     /* Now format the actual message */
-#ifdef	HAVE_VSPRINTF
+#ifdef	HAVE_VSNPRINTF
+    vsnprintf(syslogp, sizeof(outbuf) - (syslogp - outbuf), format, arglist);
+#elif	HAVE_VSPRINTF
     vsprintf(syslogp, format, arglist);
 #else	/* HAVE_VSPRINTF */
     sprintf(syslogp, format, ((int *) arglist)[0], ((int *) arglist)[1],
