--- callbacks.c.orig	Sat Jan 28 08:09:15 1995
+++ callbacks.c	Sat Oct 26 00:13:40 2002
@@ -43,10 +43,12 @@
 extern int	noshare sys_nerr;
 extern char	noshare *sys_errlist[];
 #else
+#if !defined(__FreeBSD__)
 extern int	errno;
 extern int	sys_nerr;
 extern char	*sys_errlist[];
 #endif
+#endif
 
 extern	char	otherBuf[BUFSIZ];
 
@@ -608,7 +610,7 @@
           }
 
        if (! (m = GetMailEnv("sendmail")))
-            m = XtNewString("/usr/lib/sendmail");
+            m = XtNewString("/usr/sbin/sendmail");
 #ifdef X_FACE
        else {
           add_face = (strcmp(&m[strlen(m)-14], "faces.sendmail") != 0) ? 1 : 0;
