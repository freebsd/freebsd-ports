--- appl/telnet/telnetd/ext.h.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/ext.h	Thu Jul 19 19:14:29 2001
@@ -190,6 +190,10 @@
 	wontoption P((int)),
 	writenet P((unsigned char *, int));
 
+extern int output_data __P((const char *, ...))
+        __printflike(1, 2);
+extern int output_datalen __P((const char *, size_t));
+
 #ifdef	ENCRYPTION
 extern char	*nclearto;
 #endif	/* ENCRYPTION */
