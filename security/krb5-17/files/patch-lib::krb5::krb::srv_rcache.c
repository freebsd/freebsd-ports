--- lib/krb5/krb/srv_rcache.c	1999-09-24 17:19:48.000000000 -0400
+++ lib/krb5/krb/srv_rcache.c	2003-02-03 19:29:32.000000000 -0500
@@ -48,6 +48,9 @@
     unsigned long uid = geteuid();
 #endif
     
+    if (piece == NULL)
+	return ENOMEM;
+
     rcache = (krb5_rcache) malloc(sizeof(*rcache));
     if (!rcache)
 	return ENOMEM;
