--- authvchkpw.c.orig	Thu Aug 30 03:31:13 2007
+++ authvchkpw.c	Thu Oct  4 14:59:36 2007
@@ -1,4 +1,4 @@
-i/*
+/*
 ** Copyright 1998 - 2007 Double Precision, Inc.  See COPYING for
 ** distribution information.
 */
@@ -31,7 +31,7 @@
 extern FILE *authvchkpw_file(const char *, const char *);
 
 static int auth_vchkpw_login(const char *service, char *authdata,
-	int (*callback_func)(struct authinfo *, void *), void *callback_arg)
+	int (*callback_func)(struct authinfo *, void *), void *callback_arg);
 
 struct callback_info {
 	const char *pass;
