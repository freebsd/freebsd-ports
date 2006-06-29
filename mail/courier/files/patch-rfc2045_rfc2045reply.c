--- rfc2045/rfc2045reply.c.orig	Thu Jun 29 15:07:18 2006
+++ rfc2045/rfc2045reply.c	Thu Jun 29 15:07:47 2006
@@ -592,6 +592,10 @@
 	int errflag=0;
 	struct rfc2045headerinfo *hi;
 
+#if	HAVE_UNICODE
+	const struct unicode_info *uiptr=NULL;
+#endif
+
 	oldtocc=0;
 	oldtolist=0;
 	oldfrom=0;
@@ -600,9 +604,8 @@
 	oldmsgid=0;
 	oldreferences=0;
 	whowrote=0;
-#if	HAVE_UNICODE
-	const struct unicode_info *uiptr=NULL;
 
+#if	HAVE_UNICODE
 	if (ri->charset && *(ri->charset))
 		uiptr = unicode_find(ri->charset);
 #endif
