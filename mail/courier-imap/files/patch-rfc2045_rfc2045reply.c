--- rfc2045/rfc2045reply.c~	Thu May 25 08:48:48 2006
+++ rfc2045/rfc2045reply.c	Wed May 31 10:08:03 2006
@@ -591,7 +591,9 @@
 	off_t	start_pos, end_pos, start_body, dummy;
 	int errflag=0;
 	struct rfc2045headerinfo *hi;
-
+#if	HAVE_UNICODE
+	const struct unicode_info *uiptr=NULL;
+#endif
 	oldtocc=0;
 	oldtolist=0;
 	oldfrom=0;
@@ -601,8 +603,6 @@
 	oldreferences=0;
 	whowrote=0;
 #if	HAVE_UNICODE
-	const struct unicode_info *uiptr=NULL;
-
 	if (ri->charset && *(ri->charset))
 		uiptr = unicode_find(ri->charset);
 #endif
