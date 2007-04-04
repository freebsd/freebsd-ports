--- kadmin/server/schpw.c.orig	Thu Apr 13 11:58:56 2006
+++ kadmin/server/schpw.c	Wed Apr  4 13:53:04 2007
@@ -40,6 +40,8 @@
     int numresult;
     char strresult[1024];
     char *clientstr;
+    size_t clen;
+    char *cdots;
 
     ret = 0;
     rep->length = 0;
@@ -258,9 +260,12 @@
     free(ptr);
     clear.length = 0;
 
-    krb5_klog_syslog(LOG_NOTICE, "chpw request from %s for %s: %s",
+    clen = strlen(clientstr);
+    trunc_name(&clen, &cdots);
+    krb5_klog_syslog(LOG_NOTICE, "chpw request from %s for %.*s%s: %s",
 		     inet_ntoa(((struct sockaddr_in *)&remote_addr)->sin_addr),
-		     clientstr, ret ? krb5_get_error_message (context, ret) : "success");
+		     clen, clientstr, cdots,
+		     ret ? krb5_get_error_message (context, ret) : "success");
     krb5_free_unparsed_name(context, clientstr);
 
     if (ret) {
