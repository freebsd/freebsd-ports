--- appl/telnet/telnetd/ext.h.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/ext.h	Mon Jul 23 16:44:35 2001
@@ -75,7 +75,7 @@
 
 extern char	netibuf[BUFSIZ], *netip;
 
-extern char	netobuf[BUFSIZ+NETSLOP], *nfrontp, *nbackp;
+extern char	netobuf[BUFSIZ], *nfrontp, *nbackp;
 extern char	*neturg;		/* one past last bye of urgent data */
 
 extern int	pcc, ncc;
@@ -187,8 +187,10 @@
 	tty_setsofttab P((int)),
 	tty_tspeed P((int)),
 	willoption P((int)),
-	wontoption P((int)),
-	writenet P((unsigned char *, int));
+	wontoption P((int));
+
+extern int output_data __P((const char *, ...)) __printflike(1, 2);
+extern int output_datalen __P((const char *, size_t));
 
 #ifdef	ENCRYPTION
 extern char	*nclearto;
