--- src/logmsg.c.orig	Wed Feb 14 07:55:40 2001
+++ src/logmsg.c	Mon Jul 15 21:38:30 2002
@@ -1,4 +1,4 @@
-/*  VER 079  TAB P   $Id: logmsg.c,v 1.10.2.1 2001/02/14 06:55:40 egil Exp $
+/*  VER 080  TAB P   $Id: logmsg.c,v 1.10.2.1 2001/02/14 06:55:40 egil Exp $
  *
  *  handle error messages and such...
  *
@@ -60,9 +60,9 @@
     /* 
      *  try to make a surrogate 
      *  we assume that on those architectures where this trick
-     *  doesn't work there we will surely have stdarg.h or varargs.h
+     *  doesn't work there we will surely be stdarg.h or varargs.h
      */
-#define vsprintf(buf,  fmt, ap) sprintf(buf,  fmt, arg1, arg2, arg3, arg4)
+#define vsnprintf(buf,siz,fmt,ap) snprintf(buf,siz,fmt, arg1,arg2,arg3,arg4)
 #define vfprintf(file, fmt, ap) fprintf(file, fmt, arg1, arg2, arg3, arg4)
 #endif
 
@@ -156,7 +156,7 @@
 #endif
 {
     int e;
-    char buf[BUFSIZ]; /* BUG: do we risk overwriting it? */
+    char buf[BUFSIZ];
 
 #if HAVE_VPRINTF
     va_list ap;
@@ -176,34 +176,33 @@
     case L_ERRno:
     case L_ERR:
 	e = errno;
-	vsprintf(buf, fmt, ap);
-	if (type == L_ERRno) {
-	    sprintf(buf + strlen (buf), ": %s", str_error(e));
-	}
-	strcat(buf, "\n");
+	vsnprintf(buf, sizeof(buf), fmt, ap);
 #if HAVE_SYSLOG_H
 	if (!debug_opt) {
-	    syslog(LOG_ERR, buf);
+	    syslog(LOG_ERR, "%s%s%s\n", buf,
+					((type==L_ERRno) ? ": ":""),
+					((type==L_ERRno) ? str_error(e):""));
 	} else 
 #endif
 	{
 	    clean_line();
-	    fprintf(stderr, "%s: %s", pname, buf);
+	    fprintf(stderr, "%s: %s%s%s\n", pname, buf,
+					((type==L_ERRno) ? ": ":""),
+					((type==L_ERRno) ? str_error(e):""));
 	    fflush(stderr);
 	}
 	break;
 
     case L_INFO:
-	vsprintf(buf, fmt, ap);
-	strcat(buf, "\n");
+	vsnprintf(buf, sizeof(buf), fmt, ap);
 #if HAVE_SYSLOG_H
 	if (!debug_opt) {
-	    syslog(LOG_INFO, buf);
+	    syslog(LOG_INFO, "%s\n", buf);
 	} else 
 #endif
 	{
 	    clean_line();
-	    fprintf(stderr, "%s", buf);
+	    fprintf(stderr, "%s\n", buf);
 	    fflush(stderr);
 	}
 	break;
